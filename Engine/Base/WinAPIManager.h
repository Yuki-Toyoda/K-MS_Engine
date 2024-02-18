#pragma once
#include <Windows.h>
#include <stdint.h>
#include <string>
#include "../Math/Vector2.h"

/// <summary>
/// WindowsAPIをつかさどるマネージャー
/// </summary>
class WinAPIManager
{
private: // コンストラクタ等

	// シングルトンパターンの設定
	WinAPIManager() = default;
	~WinAPIManager() = default;
	WinAPIManager(const WinAPIManager&) = delete;
	const WinAPIManager& operator=(const WinAPIManager&);

public: // 静的なメンバ関数

	/// <summary>
	/// シングルトンインスタンスの取得
	/// </summary>
	/// <returns>シングルトンインスタンス</returns>
	static WinAPIManager* GetInstance() {
		// クラスのインスタンスを取得
		static WinAPIManager instance;
		// インスタンスを返す
		return &instance;
	}

	/// <summary>
	/// ウィンドウプロシージャ
	/// </summary>
	/// <param name="hwnd">ウィンドウハンドル</param>
	/// <param name="msg">メッセージ番号</param>
	/// <param name="wparam">メッセージ番号1</param>
	/// <param name="lparam">メッセージ番号2</param>
	/// <returns>成否</returns>
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public: // メンバ関数

	/// <summary>
	/// ゲームウィンドウ生成関数
	/// </summary>
	/// <param name="title">ウィンドウ名</param>
	/// <param name="width">画面横幅</param>
	/// <param name="height">画面縦幅</param>
	/// <param name="isFullScreen">フルスクリーンにするか</param>
	void CreateGameWindow(const std::wstring& title = L"KEngine", int32_t width = 1280, int32_t height = 720, bool isFullScreen = false);

	/// <summary>
	/// ゲームウィンドウの破棄関数
	/// </summary>
	void TerminateGameWindow();

	/// <summary>
	/// メッセージの処理
	/// </summary>
	/// <returns>終了がどうか</returns>
	bool ProcessMessage();

public: // アクセッサ等

	/// <summary>
	/// ウィンドウハンドルの取得
	/// </summary>
	/// <returns>ウィンドウハンドル</returns>
	inline HWND GetHwnd() const { return hwnd_; }

	/// <summary>
	/// HINSTANCEの取得
	/// </summary>
	/// <returns>HINSTANCE</returns>
	inline HINSTANCE GetHInstance() const { return wndClass_.hInstance; }

	/// <summary>
	/// ウィンドウ名ゲッター
	/// </summary>
	/// <returns></returns>
	inline std::wstring GetWindowName() const { return windowName_; }

	/// <summary>
	/// ウィンドウのモード変更関数
	/// </summary>
	void ChangeWindowMode();
	/// <summary>
	/// フルスクリーン状態変更関数
	/// </summary>
	void ChageFullScreen();

	/// <summary>
	/// ウィンドウサイズゲッター
	/// </summary>
	/// <returns>ウィンドウサイズ</returns>
	Vector2 GetWindowSize() const;

	/// <summary>
	/// クライアント領域ゲッター
	/// </summary>
	/// <returns>クライアント領域</returns>
	const Vector2& GetClientSize() const { return clientSize_; }

private: // メンバ変数

	// Window関連
	HWND hwnd_ = nullptr;	  // ウィンドウハンドル
	WNDCLASSEX wndClass_{};   // ウィンドウクラス
	UINT windowStyle_;		  // ウィンドウのスタイル
	RECT windowRect_;		  // ウィンドウの描画範囲
	std::wstring windowName_; // ウィンドウ名

	// フルスクリーントリガー
	bool isFullScreen_ = false;
	// クライアント領域
	Vector2 clientSize_;

};

 