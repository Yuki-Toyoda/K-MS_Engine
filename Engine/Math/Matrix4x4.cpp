#include "Matrix4x4.h"
#include <cmath>

Matrix4x4::Matrix4x4()
{
	// 行列要素の初期化
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
	m[2][3] = 0.0f;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

Matrix4x4::Matrix4x4(const Matrix4x4& mat)
{
	// 値の代入
	*this = mat;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& mat) const noexcept
{
	// 結果格納用
	Matrix4x4 result;

	// 計算を行う
	result.m[0][0] = this->m[0][0] + mat.m[0][0];
	result.m[1][0] = this->m[1][0] + mat.m[1][0];
	result.m[2][0] = this->m[2][0] + mat.m[2][0];
	result.m[3][0] = this->m[3][0] + mat.m[3][0];

	result.m[0][1] = this->m[0][1] + mat.m[0][1];
	result.m[1][1] = this->m[1][1] + mat.m[1][1];
	result.m[2][1] = this->m[2][1] + mat.m[2][1];
	result.m[3][1] = this->m[3][1] + mat.m[3][1];

	result.m[0][2] = this->m[0][2] + mat.m[0][2];
	result.m[1][2] = this->m[1][2] + mat.m[1][2];
	result.m[2][2] = this->m[2][2] + mat.m[2][2];
	result.m[3][2] = this->m[3][2] + mat.m[3][2];

	result.m[0][3] = this->m[0][3] + mat.m[0][3];
	result.m[1][3] = this->m[1][3] + mat.m[1][3];
	result.m[2][3] = this->m[2][3] + mat.m[2][3];
	result.m[3][3] = this->m[3][3] + mat.m[3][3];

	// 計算後の値を返還する
	return result;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& mat) const noexcept
{
	// 結果格納用
	Matrix4x4 result;

	// 計算を行う
	result.m[0][0] = this->m[0][0] - mat.m[0][0];
	result.m[1][0] = this->m[1][0] - mat.m[1][0];
	result.m[2][0] = this->m[2][0] - mat.m[2][0];
	result.m[3][0] = this->m[3][0] - mat.m[3][0];

	result.m[0][1] = this->m[0][1] - mat.m[0][1];
	result.m[1][1] = this->m[1][1] - mat.m[1][1];
	result.m[2][1] = this->m[2][1] - mat.m[2][1];
	result.m[3][1] = this->m[3][1] - mat.m[3][1];

	result.m[0][2] = this->m[0][2] - mat.m[0][2];
	result.m[1][2] = this->m[1][2] - mat.m[1][2];
	result.m[2][2] = this->m[2][2] - mat.m[2][2];
	result.m[3][2] = this->m[3][2] - mat.m[3][2];

	result.m[0][3] = this->m[0][3] - mat.m[0][3];
	result.m[1][3] = this->m[1][3] - mat.m[1][3];
	result.m[2][3] = this->m[2][3] - mat.m[2][3];
	result.m[3][3] = this->m[3][3] - mat.m[3][3];

	// 計算後の値を返還する
	return result;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& mat) const noexcept
{
	// 結果格納用
	Matrix4x4 result;

	// 計算を行う
	result.m[0][0] = (this->m[0][0] * mat.m[0][0]) + (this->m[0][1] * mat.m[1][0]) + (this->m[0][2] * mat.m[2][0]) + (this->m[0][3] * mat.m[3][0]);
	result.m[1][0] = (this->m[1][0] * mat.m[0][0]) + (this->m[1][1] * mat.m[1][0]) + (this->m[1][2] * mat.m[2][0]) + (this->m[1][3] * mat.m[3][0]);
	result.m[2][0] = (this->m[2][0] * mat.m[0][0]) + (this->m[2][1] * mat.m[1][0]) + (this->m[2][2] * mat.m[2][0]) + (this->m[2][3] * mat.m[3][0]);
	result.m[3][0] = (this->m[3][0] * mat.m[0][0]) + (this->m[3][1] * mat.m[1][0]) + (this->m[3][2] * mat.m[2][0]) + (this->m[3][3] * mat.m[3][0]);

	result.m[0][1] = (this->m[0][0] * mat.m[0][1]) + (this->m[0][1] * mat.m[1][1]) + (this->m[0][2] * mat.m[2][1]) + (this->m[0][3] * mat.m[3][1]);
	result.m[1][1] = (this->m[1][0] * mat.m[0][1]) + (this->m[1][1] * mat.m[1][1]) + (this->m[1][2] * mat.m[2][1]) + (this->m[1][3] * mat.m[3][1]);
	result.m[2][1] = (this->m[2][0] * mat.m[0][1]) + (this->m[2][1] * mat.m[1][1]) + (this->m[2][2] * mat.m[2][1]) + (this->m[2][3] * mat.m[3][1]);
	result.m[3][1] = (this->m[3][0] * mat.m[0][1]) + (this->m[3][1] * mat.m[1][1]) + (this->m[3][2] * mat.m[2][1]) + (this->m[3][3] * mat.m[3][1]);

	result.m[0][2] = (this->m[0][0] * mat.m[0][2]) + (this->m[0][1] * mat.m[1][2]) + (this->m[0][2] * mat.m[2][2]) + (this->m[0][3] * mat.m[3][2]);
	result.m[1][2] = (this->m[1][0] * mat.m[0][2]) + (this->m[1][1] * mat.m[1][2]) + (this->m[1][2] * mat.m[2][2]) + (this->m[1][3] * mat.m[3][2]);
	result.m[2][2] = (this->m[2][0] * mat.m[0][2]) + (this->m[2][1] * mat.m[1][2]) + (this->m[2][2] * mat.m[2][2]) + (this->m[2][3] * mat.m[3][2]);
	result.m[3][2] = (this->m[3][0] * mat.m[0][2]) + (this->m[3][1] * mat.m[1][2]) + (this->m[3][2] * mat.m[2][2]) + (this->m[3][3] * mat.m[3][2]);

	result.m[0][3] = (this->m[0][0] * mat.m[0][3]) + (this->m[0][1] * mat.m[1][3]) + (this->m[0][2] * mat.m[2][3]) + (this->m[0][3] * mat.m[3][3]);
	result.m[1][3] = (this->m[1][0] * mat.m[0][3]) + (this->m[1][1] * mat.m[1][3]) + (this->m[1][2] * mat.m[2][3]) + (this->m[1][3] * mat.m[3][3]);
	result.m[2][3] = (this->m[2][0] * mat.m[0][3]) + (this->m[2][1] * mat.m[1][3]) + (this->m[2][2] * mat.m[2][3]) + (this->m[2][3] * mat.m[3][3]);
	result.m[3][3] = (this->m[3][0] * mat.m[0][3]) + (this->m[3][1] * mat.m[1][3]) + (this->m[3][2] * mat.m[2][3]) + (this->m[3][3] * mat.m[3][3]);

	// 計算後の値を返還する
	return result;
}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& mat) noexcept
{
	// 値の代入
	this->m[0][0] = mat.m[0][0];
	this->m[1][0] = mat.m[1][0];
	this->m[2][0] = mat.m[2][0];
	this->m[3][0] = mat.m[3][0];

	this->m[0][1] = mat.m[0][1];
	this->m[1][1] = mat.m[1][1];
	this->m[2][1] = mat.m[2][1];
	this->m[3][1] = mat.m[3][1];

	this->m[0][2] = mat.m[0][2];
	this->m[1][2] = mat.m[1][2];
	this->m[2][2] = mat.m[2][2];
	this->m[3][2] = mat.m[3][2];

	this->m[0][3] = mat.m[0][3];
	this->m[1][3] = mat.m[1][3];
	this->m[2][3] = mat.m[2][3];
	this->m[3][3] = mat.m[3][3];

	// 代入した値を返還する
	return *this;
}

Matrix4x4& Matrix4x4::operator=(Matrix4x4&& mat) noexcept
{
	// 値の代入
	this->m[0][0] = std::move(mat.m[0][0]);
	this->m[1][0] = std::move(mat.m[1][0]);
	this->m[2][0] = std::move(mat.m[2][0]);
	this->m[3][0] = std::move(mat.m[3][0]);

	this->m[0][1] = std::move(mat.m[0][1]);
	this->m[1][1] = std::move(mat.m[1][1]);
	this->m[2][1] = std::move(mat.m[2][1]);
	this->m[3][1] = std::move(mat.m[3][1]);

	this->m[0][2] = std::move(mat.m[0][2]);
	this->m[1][2] = std::move(mat.m[1][2]);
	this->m[2][2] = std::move(mat.m[2][2]);
	this->m[3][2] = std::move(mat.m[3][2]);

	this->m[0][3] = std::move(mat.m[0][3]);
	this->m[1][3] = std::move(mat.m[1][3]);
	this->m[2][3] = std::move(mat.m[2][3]);
	this->m[3][3] = std::move(mat.m[3][3]);

	// 代入した値を返還する
	return *this;
}

Matrix4x4 Matrix4x4::operator+=(const Matrix4x4& mat) noexcept
{
	// 計算を行う
	this->m[0][0] += mat.m[0][0];
	this->m[1][0] += mat.m[1][0];
	this->m[2][0] += mat.m[2][0];
	this->m[3][0] += mat.m[3][0];

	this->m[0][1] += mat.m[0][1];
	this->m[1][1] += mat.m[1][1];
	this->m[2][1] += mat.m[2][1];
	this->m[3][1] += mat.m[3][1];

	this->m[0][2] += mat.m[0][2];
	this->m[1][2] += mat.m[1][2];
	this->m[2][2] += mat.m[2][2];
	this->m[3][2] += mat.m[3][2];

	this->m[0][3] += mat.m[0][3];
	this->m[1][3] += mat.m[1][3];
	this->m[2][3] += mat.m[2][3];
	this->m[3][3] += mat.m[3][3];

	// 計算後の値を返還する
	return *this;
}

Matrix4x4 Matrix4x4::operator-=(const Matrix4x4& mat) noexcept
{
	// 計算を行う
	this->m[0][0] -= mat.m[0][0];
	this->m[1][0] -= mat.m[1][0];
	this->m[2][0] -= mat.m[2][0];
	this->m[3][0] -= mat.m[3][0];

	this->m[0][1] -= mat.m[0][1];
	this->m[1][1] -= mat.m[1][1];
	this->m[2][1] -= mat.m[2][1];
	this->m[3][1] -= mat.m[3][1];

	this->m[0][2] -= mat.m[0][2];
	this->m[1][2] -= mat.m[1][2];
	this->m[2][2] -= mat.m[2][2];
	this->m[3][2] -= mat.m[3][2];

	this->m[0][3] -= mat.m[0][3];
	this->m[1][3] -= mat.m[1][3];
	this->m[2][3] -= mat.m[2][3];
	this->m[3][3] -= mat.m[3][3];

	// 計算後の値を返還する
	return *this;
}

const Matrix4x4& Matrix4x4::Identity()
{
	// 単位行列の生成
	this->m[0][0] = 1.0f;
	this->m[0][1] = 0.0f;
	this->m[0][2] = 0.0f;
	this->m[0][3] = 0.0f;

	this->m[1][0] = 0.0f;
	this->m[1][1] = 1.0f;
	this->m[1][2] = 0.0f;
	this->m[1][3] = 0.0f;

	this->m[2][0] = 0.0f;
	this->m[2][1] = 0.0f;
	this->m[2][2] = 1.0f;
	this->m[2][3] = 0.0f;

	this->m[3][0] = 0.0f;
	this->m[3][1] = 0.0f;
	this->m[3][2] = 0.0f;
	this->m[3][3] = 1.0f;

	// 生成した単位行列の返還
	return *this;
}
