#include "WinAPIManager.h"
#include "../Input/Input.h"
#pragma comment(lib, "winmm.lib")

//#include "../../Externals/imgui/imgui_impl_win32.h"
//extern IMGUI_IMPL_API LRESULT
//ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT WinAPIManager::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	// imGui1でウィンドウの入力を受け取る
	/*if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam)) {
		return true;
	}*/
		
	// メッセージに応じてゲーム固有の処理を行う
	switch (msg)
	{
		// ウィンドウが破棄されたら
	case WM_DESTROY:
		// OSに対してアプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}

	// 標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);

}

void WinAPIManager::CreateGameWindow(const std::wstring& title, int32_t width, int32_t height, bool isFullScreen)
{
	// ウィンドウ名の設定
	windowName_ = title;

	// 最大化ボタン無効、サイズ変更を行えないように
	windowStyle_ = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);

	// ウィンドウクラスの設定
	wndClass_.cbSize = sizeof(WNDCLASSEX);			 // バッファサイズ設定
	wndClass_.lpfnWndProc = WindowProc;				 // ウィンドウプロシージャ
	wndClass_.lpszClassName = windowName_.c_str();   // ウィンドウ名設定
	wndClass_.hInstance = GetModuleHandle(nullptr);	 // インスタンス設定
	wndClass_.hCursor = LoadCursor(NULL, IDC_ARROW); // カーソル設定

	// 設定したウィンドウクラスをOSに登録する
	RegisterClassEx(&wndClass_);

	// クライアントサイズの取得
	clientSize_ = { static_cast<float>(width), static_cast<float>(height) };

	// 描画範囲設定
	windowRect_ = { 0, 0, width, height };

	// 指定されたサイズになるようにウィンドウサイズを計算する
	AdjustWindowRect(&windowRect_, windowStyle_, false);

	// 設定を元にウィンドウ生成
	hwnd_ = CreateWindow(
		wndClass_.lpszClassName,
		windowName_.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		windowRect_.right - windowRect_.left,
		windowRect_.bottom - windowRect_.top,
		nullptr,
		nullptr,
		wndClass_.hInstance,
		nullptr
	);

	// ウィンドウスタイルを再設定
	windowStyle_ &= ~WS_THICKFRAME;

	// ウィンドウの属性変更
	SetWindowLong(hwnd_, GWL_STYLE, windowStyle_);
	// ウィンドウの描画位置、最前面の設定
	SetWindowPos(
		hwnd_, NULL, 0, 0, 0, 0, (SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED));
	// ウィンドウの表示
	ShowWindow(hwnd_, SW_NORMAL);

	// フルスクリーントリガー取得
	isFullScreen_ = isFullScreen;

	// フルスクリーン状態にする場合
	if (isFullScreen_) {
		// ウィンドウのタイプを変更
		ChangeWindowMode();
	}
}

void WinAPIManager::TerminateGameWindow()
{
	// ウィンドウの破棄を行う
	CloseWindow(hwnd_);
}

bool WinAPIManager::ProcessMessage()
{
	// メッセージを受け取る
	MSG msg{};

	// メッセージがあるのか
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg); // キー入力メッセージの処理
		DispatchMessage(&msg); // ウィンドウプロシージャにメッセージを送る
	}

	// 終了メッセージが来た場合ループを抜ける
	if (msg.message == WM_QUIT) {
		return true;
	}

	// 終了メッセージが来ていない場合は処理を続ける
	return false;
}

void WinAPIManager::ChangeWindowMode()
{
	// フルスクリーントリガーが有効の時
	if (isFullScreen_) {
		// 通常ウィンドウの時の状態を保存
		windowStyle_ = GetWindowLong(hwnd_, GWL_STYLE);
		GetWindowRect(hwnd_, &windowRect_);

		// フルスクリーンにする
		SetWindowLong(hwnd_, GWL_STYLE, WS_POPUP);
		SetWindowPos(hwnd_, HWND_TOP, 0, 0,
			GetSystemMetrics(SM_CXSCREEN),
			GetSystemMetrics(SM_CYSCREEN),
			SWP_FRAMECHANGED | SWP_SHOWWINDOW
		);
	}
	else {
		// 通常のウィンドウに戻す
		SetWindowLong(hwnd_, GWL_STYLE, windowStyle_);
		SetWindowPos(
			hwnd_,
			NULL,
			windowRect_.left, windowRect_.top,
			windowRect_.right - windowRect_.left,
			windowRect_.bottom - windowRect_.top,
			SWP_FRAMECHANGED | SWP_SHOWWINDOW
		);
	}
}

void WinAPIManager::ChageFullScreen()
{
	// F11キーが押された場合
	if (Input::GetInstance()->TriggerKey(DIK_F11)) {
		// フルスクリーントリガーを切り替え
		isFullScreen_ = !isFullScreen_;
		// ウィンドウモードを変更
		ChangeWindowMode();
	}
}

Vector2 WinAPIManager::GetWindowSize() const
{
	// ウィンドウのサイズを返還する
	return Vector2(
		static_cast<float>(windowRect_.right),
		static_cast<float>(windowRect_.bottom));
}
