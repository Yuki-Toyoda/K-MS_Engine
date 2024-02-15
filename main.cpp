#include <Windows.h>

// Windowsアプリでのエントリーポイント関数(いわばメイン関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// テスト用に出力ウィンドウに文字出力
	OutputDebugStringA("Hello, DirectX!\n");

	// 終了
	return 0;
}