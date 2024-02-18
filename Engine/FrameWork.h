#pragma once
#include "Base/WinAPIManager.h"
#include "Input/Input.h"

/// <summary>
/// フレームワーククラス
/// </summary>
class FrameWork
{
public: // 仮想デストラクタ

	// 仮想デストラクタ
	virtual ~FrameWork() = default;

public: // メンバ関数

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Init();

	/// <summary>
	/// 更新処理関数
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 終了処理
	/// </summary>
	virtual void Finalize();

	/// <summary>
	/// エンジン実行関数
	/// </summary>
	void Run();

public: // アクセッサ等

	/// <summary>
	/// ゲーム終了フラグのゲッター
	/// </summary>
	/// <returns>ゲームを終了するかどうか</returns>
	virtual bool GetIsEndGameRequest() { return endGameRequest_; }

private: // メンバ変数

	// WindowsAPIマネージャーのインスタンス格納用
	WinAPIManager* winAPI_ = nullptr;

	// 入力クラスのインスタンス格納用
	Input* input_ = nullptr;

	// ゲーム終了フラグ
	bool endGameRequest_ = false;

};

