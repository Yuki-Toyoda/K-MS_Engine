#pragma once
#include "../Transform/WorldTransform.h"
#include "../Math/Vector2.h"
#include "../Math/Vector4.h"
#include "../Resource/Texture/Texture.h"
#include "../Resource/Material/Material.h"
#include <wrl.h>
#include <d3d12.h>

// クラスの前方宣言
class CommandManager;

// 頂点構造体
struct Vertex {
	Vector3 position;							// 座標
	Vector2 texCoord;							// uv座標
	Vector3 normal;								// 法線
	Vector4 color = { 1.0f, 1.0f, 1.0f, 1.0f }; // 色
};

/// <summary>
/// 形状情報の基底クラス
/// </summary>
class IPrimitive
{
public: // パブリックなサブクラス

	/// <summary>
	/// ブレンドモード列挙子
	/// </summary>
	enum kBlendMode {
		kBlendNormal,	// ノーマルaブレンド
		kBlendAdd,		// 加算合成
		kBlendSubtract, // 減算合成
		kBlendMultiply, // 乗算合成
		kBlendScreen,	// スクリーン合成
	};

	/// <summary>
	/// 描画タイプ列挙子
	/// </summary>
	enum kPrimitiveType {
		kModelNormal,	// 通常
		kModelParticle, // パーティクル
		kModelSprite,   // スプライト
	};

public: // メンバ関数

	/// <summary>
	/// (呼び出し禁止)コンストラクタ
	/// </summary>
	/// <param name="manager">マネージャー</param>
	IPrimitive(CommandManager* manager);

	/// <summary>
	/// (呼び出し禁止)頂点配列を形状の頂点数にリサイズする関数
	/// </summary>
	virtual void ResizeVertices();
	/// <summary>
	/// (呼び出し禁止)インデックス情報配列を形状の情報をもとにリサイズする関数
	/// </summary>
	virtual void ResizeIndexes();

	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw(CommandManager* manager);

	/// <summary>
	/// ImGui表示関数
	/// </summary>
	virtual void DisplayImGui();

public: // アクセッサ等

	/// <summary>
	/// 頂点数ゲッター
	/// </summary>
	/// <returns></returns>
	virtual int GetVertexCount() const;
	/// <summary>
	/// インデックス情報数ゲッター
	/// </summary>
	/// <returns></returns>
	virtual int GetIndexCount() const;

public: // パブリックなメンバ変数

	// 形状名称
	std::string name_ = "primitive";

	// 頂点
	std::vector<Vertex> vertices_;
	// インデックス情報
	std::vector<uint32_t> indexes_;

	// 描画中心座標
	WorldTransform* transform_;

	// マテリアルz
	Material material_;
	// 使用するテクスチャ
	Texture* texture_ = nullptr;

	// 全頂点カラー
	// ここに情報が入っている場合全頂点の色にこの色を適用する
	Vector4* commonColor = nullptr;

	// モデルタイプ
	// kModelNormal ... 通常の3Dモデル描画
	// kModelParticle ... パーティクル描画
	// kModelSprite ... スプライト描画
	kPrimitiveType primitiveType_ = kModelNormal;

	// 表示状態
	bool isActive_ = true;
	// 破壊トリガー
	bool isDestroy_ = false;

	// ビルボード用行列格納用
	Matrix4x4 billboardMat_;

	// 描画順
	int32_t layerNo_ = 0;

	// UIとして使用するか
	bool isUI_ = false;
};

/// <summary>
/// IPrimitiveを継承したクラスを選択できるテンプレート
/// </summary>
template <class SelectPrimitive>
concept IsIPrimitive = std::is_base_of<IPrimitive, SelectPrimitive>::value;