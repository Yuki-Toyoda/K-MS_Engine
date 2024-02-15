#pragma once

// クラスの前方宣言
class Vector3;

/// <summary>
/// 4x4行列クラス
/// </summary>
class Matrix4x4 final
{
public: // コンストラクタ等

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Matrix4x4();

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="mat">行列</param>
	Matrix4x4(const Matrix4x4& mat);

	// 既定のデストラクタを使用する
	~Matrix4x4() = default;

public: // 演算子のオーバーロード

	/// <summary>
	/// 演算子オーバーロード(+)
	/// </summary>
	/// <param name="mat">右辺値</param>
	/// <returns>計算後値</returns>
	Matrix4x4 operator+(const Matrix4x4& mat) const noexcept;
	/// <summary>
	/// 演算子オーバーロード(-)
	/// </summary>
	/// <param name="mat">右辺値</param>
	/// <returns>計算後値</returns>
	Matrix4x4 operator-(const Matrix4x4& mat) const noexcept;
	/// <summary>
	/// 演算子オーバーロード(*)
	/// </summary>
	/// <param name="mat">右辺値</param>
	/// <returns>計算後値</returns>
	Matrix4x4 operator*(const Matrix4x4& mat) const noexcept;

	/// <summary>
	/// 演算子オーバーロード(=)
	/// </summary>
	/// <param name="mat">右辺値</param>
	/// <returns>計算後値</returns>
	Matrix4x4& operator=(const Matrix4x4& mat) noexcept;
	/// <summary>
	/// 演算子オーバーロード(=)
	/// </summary>
	/// <param name="mat">右辺値</param>
	/// <returns>計算後値</returns>
	Matrix4x4& operator=(Matrix4x4&& mat) noexcept;

	/// <summary>
	/// 演算子オーバーロード(+=)
	/// </summary>
	/// <param name="mat">右辺値</param>
	/// <returns>計算後値</returns>
	Matrix4x4 operator+=(const Matrix4x4& mat) noexcept;
	/// <summary>
	/// 演算子オーバーロード(-=)
	/// </summary>
	/// <param name="mat">右辺値</param>
	/// <returns>計算後値</returns>
	Matrix4x4 operator-=(const Matrix4x4& mat) noexcept;

public: // メンバ関数

	/// <summary>
	/// 単位行列生成
	/// </summary>
	/// <returns>単位行列</returns>
	const Matrix4x4& Identity();

public: // 静的なメンバ関数

	

public: // メンバ変数

	// 行列要素
	float m[4][4];

};

