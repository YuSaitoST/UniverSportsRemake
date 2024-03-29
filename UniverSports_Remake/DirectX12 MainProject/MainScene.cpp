//
// MainScene.cpp
//

#include "Base/pch.h"
#include "Base/dxtk.h"
#include "SceneFactory.h"
#include "_Classes/_InputManager/UseKeyChecker.h"
#include "_Classes/_MainLight/MainLight.h"
#include "_Classes/_FileNames/FileNames.h"

#ifndef _DEBUG
#pragma comment (lib, "BulletDynamics.lib")
#pragma comment (lib, "BulletCollision.lib")
#pragma comment (lib, "LinearMath.lib")
#else
#pragma comment (lib, "BulletDynamics_Debug.lib")
#pragma comment (lib, "BulletCollision_Debug.lib")
#pragma comment (lib, "LinearMath_Debug.lib")
#endif

// Initialize member variables.
MainScene::MainScene()
{
	DontDestroy->NowScene_	= NextScene::MainScene;

	descriptorHeap_			= nullptr;
	spriteBatch_			= nullptr;

	collision_config_ = new btDefaultCollisionConfiguration();		//! 衝突検出方法(デフォルト)
	btDefaultCollisionConfiguration*		_collision_config		= new btDefaultCollisionConfiguration();					//! 衝突検出方法(デフォルト)
	std::unique_ptr<btCollisionDispatcher>	_collision_dispatcher	= std::make_unique<btCollisionDispatcher>(collision_config_);
	std::unique_ptr<btBroadphaseInterface>	_broadphase				= std::make_unique<btDbvtBroadphase>();						//! ブロードフェーズ法の設定
	std::unique_ptr<btConstraintSolver>		_solver					= std::make_unique<btSequentialImpulseConstraintSolver>();	//! 拘束のソルバ設定
	physics_world_	= std::make_shared<btDiscreteDynamicsWorld>(_collision_dispatcher.release(), _broadphase.release(), _solver.release(), collision_config_);

	bgm_			= std::make_unique<SoundPlayer>();
	field_			= std::make_unique<GameField>((int)US2D::Layer::MAIN::UI_HOLE);
	gameController_	= std::make_unique<GameController>();
	m_object_		= std::make_unique<ObjectManager>();
}

// Initialize a variable and audio resources.
void MainScene::Initialize()
{
	DX12Effect.Initialize();
	std::unique_ptr<MainLight> _light = std::make_unique<MainLight>();
	_light->Register();

	bgm_->Initialize(USFN_SOUND::BGM::MAIN, SOUND_TYPE::BGM, 0.0f);
	m_object_->Initialize();
	gameController_->Initialize();

	physics_world_->setGravity(btVector3(0.0f, 0.0f, 0.0f));
	m_object_->AddWorld(physics_world_.get());
}

// Allocate all memory the Direct3D and Direct2D resources.
void MainScene::LoadAssets()
{
	DX12Effect.SetCamera((DX12::CAMERA)Camera.GetCamera());

	descriptorHeap_ = DX12::CreateDescriptorHeap(DXTK->Device, 1);

	ResourceUploadBatch resourceUploadBatch(DXTK->Device);
	resourceUploadBatch.Begin();

	RenderTargetState rtState(DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_FORMAT_D32_FLOAT);
	SpriteBatchPipelineStateDescription pd(rtState, &CommonStates::NonPremultiplied);
	D3D12_VIEWPORT viewport = { 0.0f, 0.0f, 1280.0f, 720.0f, D3D12_MIN_DEPTH, D3D12_MAX_DEPTH };

	spriteBatch_ = DX12::CreateSpriteBatch(DXTK->Device, resourceUploadBatch, pd, &viewport);

	dx9GpuDescriptor_ = DXTK->Direct3D9->CreateShaderResourceView(descriptorHeap_.get(), 0);

	auto uploadResourcesFinished = resourceUploadBatch.End(DXTK->CommandQueue);
	uploadResourcesFinished.wait();

	DXTK->Direct3D9->SetRenderState(NormalizeNormals_Enable);

	m_object_->LoadAssets();
	field_->LoadAsset();
	gameController_->LoadAssets();
	bgm_->Play();
}

// Releasing resources required for termination.
void MainScene::Terminate()
{
	DXTK->ResetAudioEngine();
	DXTK->WaitForGpu();

	// TODO: Add your Termination logic here.

	m_object_->RemoveWorld(physics_world_.get());

	delete collision_config_;
}

// Direct3D resource cleanup.
void MainScene::OnDeviceLost()
{
	DX12Effect.Reset();
}

// Restart any looped sounds here
void MainScene::OnRestartSound()
{
	bgm_->OnRestartSound();
}

// Updates the scene.
NextScene MainScene::Update(const float deltaTime)
{
	// If you use 'deltaTime', remove it.
	UNREFERENCED_PARAMETER(deltaTime);

	// TODO: Add your game logic here.

	//入力状態を調べる
	INPSystem.Accepts();

	//物体の更新
	m_object_->Update(deltaTime);
	
	//背景の更新
	field_->Update();

	//物理演算の更新
	physics_world_->stepSimulation(deltaTime, 10);
	
	//エフェクトの更新
	DX12Effect.Update(deltaTime);

	return (NextScene)gameController_->Update(deltaTime);
}

// Draws the scene.
void MainScene::Render()
{
	DXTK->Direct3D9->Clear(DX9::Colors::RGBA(0, 0, 0, 255));  // 画面をクリア
	DXTK->Direct3D9->BeginScene();  // シーンの開始を宣言

	m_object_->RenderModels();

	DX9::SpriteBatch->Begin();  // スプライトの描画を開始
	
	field_->Render();
	gameController_->Render();
	m_object_->RenderSprites();

	DX9::SpriteBatch->End();  // スプライトの描画を終了

	m_object_->RenderAlphas();

	DXTK->Direct3D9->EndScene();  // シーンの終了を宣言

	DXTK->Direct3D9->UpdateResource();

	DXTK->ResetCommand();
	DXTK->ClearRenderTarget(Colors::CornflowerBlue);

	const auto heapes = descriptorHeap_->Heap();
	DXTK->CommandList->SetDescriptorHeaps(1, &heapes);

	spriteBatch_->Begin(DXTK->CommandList);
	spriteBatch_->Draw(dx9GpuDescriptor_, XMUINT2(1280, 720), SimpleMath::Vector2(0.0f, 0.0f));

	spriteBatch_->End();

	DX12Effect.Renderer();

	DXTK->Direct3D9->WaitUpdate();
	DXTK->ExecuteCommandList();
}