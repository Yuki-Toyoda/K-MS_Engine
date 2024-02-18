#include <Windows.h>
#include "Engine/FrameWork.h"

// Windowsアプリでのエントリーポイント関数(いわばメイン関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ゲームクラス生成
	FrameWork* work = new FrameWork();

	// エンジン実行
	work->Run();

	// 終了
	return 0;
}