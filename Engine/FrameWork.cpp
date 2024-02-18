#include "FrameWork.h"

void FrameWork::Init()
{
	// COMの初期化
	CoInitializeEx(0, COINIT_MULTITHREADED);

	// WindowsAPIマネージャーのインスタンス取得
	winAPI_ = WinAPIManager::GetInstance();
	// ウィンドウ生成
	winAPI_->CreateGameWindow();

	// 入力クラスのインスタンス取得
	input_ = Input::GetInstance();
	// 入力クラスの初期化
	input_->Init();
}

void FrameWork::Update()
{
	// ゲームが終了するメッセージを受けとったら
	if (winAPI_->ProcessMessage()) {
		// ゲーム終了
		endGameRequest_ = true;
	}

	// 入力の更新を行う
	input_->Update();
}

void FrameWork::Finalize()
{
	// ゲームウィンドウを閉じる
	winAPI_->TerminateGameWindow();

	// COM終了
	CoUninitialize();
}

void FrameWork::Run()
{
	// フレームワークの初期化を行う
	Init();

	// メインループ
	while (true) {

		// フレームワークの更新処理を呼び出す
		Update();

		// 終了リクエストを受け取った場合はゲームを終了させる
		if (GetIsEndGameRequest()) {
			break;
		}

	}

	// ゲームの終了処理を行う
	Finalize();
}
