#include "Vector3.h"
#include <cmath>

Vector3::Vector3() noexcept
{
	// 値の初期化
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float x, float y, float z) noexcept
{
	// 値の代入
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(const Vector3& v) noexcept
{
	// 値の代入
	*this = v;
}

Vector3 Vector3::operator+(const Vector3& v) const noexcept
{
	// 結果格納用
	Vector3 result;

	// 値の計算を行う
	result.x = this->x + v.x;
	result.y = this->y + v.y;
	result.z = this->z + v.z;

	// 計算後の値を返す
	return result;
}

Vector3 Vector3::operator-(const Vector3& v) const noexcept
{
	// 結果格納用
	Vector3 result;

	// 値の計算を行う
	result.x = this->x - v.x;
	result.y = this->y - v.y;
	result.z = this->z - v.z;

	// 計算後の値を返す
	return result;
}

Vector3 Vector3::operator*(const Vector3& v) const noexcept
{
	// 結果格納用
	Vector3 result;

	// 値の計算を行う
	result.x = this->x * v.x;
	result.y = this->y * v.y;
	result.z = this->z * v.z;

	// 計算後の値を返す
	return result;
}

Vector3 Vector3::operator/(const Vector3& v) const noexcept
{
	// 結果格納用
	Vector3 result;

	// 値の計算を行う
	result.x = this->x / v.x;
	result.y = this->y / v.y;
	result.z = this->z / v.z;

	// 計算後の値を返す
	return result;
}

Vector3& Vector3::operator=(const Vector3& v) noexcept
{
	// 値の代入を行う
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;

	// 代入した値を返還する
	return *this;
}

Vector3& Vector3::operator=(Vector3&& v) noexcept
{
	// 値の代入を行う
	this->x = std::move(v.x);
	this->y = std::move(v.y);
	this->z = std::move(v.z);

	// 代入した値を返還する
	return *this;
}

Vector3 Vector3::operator+=(const Vector3& v) noexcept
{
	// 計算を行う
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;

	// 計算後の値を返還する
	return *this;
}

Vector3 Vector3::operator-=(const Vector3& v) noexcept
{
	// 計算を行う
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;

	// 計算後の値を返還する
	return *this;
}

Vector3 Vector3::operator*=(const Vector3& v) noexcept
{
	// 計算を行う
	this->x *= v.x;
	this->y *= v.y;
	this->z *= v.z;

	// 計算後の値を返還する
	return *this;
}

Vector3 Vector3::operator/=(const Vector3& v) noexcept
{
	// 計算を行う
	this->x /= v.x;
	this->y /= v.y;
	this->z /= v.z;

	// 計算後の値を返還する
	return *this;
}

Vector3 Vector3::operator*(const float& f) const noexcept
{
	// 結果格納用
	Vector3 result;

	// 値の計算を行う
	result.x = this->x * f;
	result.y = this->y * f;
	result.z = this->z * f;

	// 計算後の値を返す
	return result;
}

Vector3 Vector3::operator/(const float& f) const noexcept
{
	// 結果格納用
	Vector3 result;

	// 値の計算を行う
	result.x = this->x / f;
	result.y = this->y / f;
	result.z = this->z / f;

	// 計算後の値を返す
	return result;
}

Vector3 Vector3::operator*=(const float& f) noexcept
{
	// 計算を行う
	this->x *= f;
	this->y *= f;
	this->z *= f;

	// 計算後の値を返還する
	return *this;
}

Vector3 Vector3::operator/=(const float& f) noexcept
{
	// 計算を行う
	this->x /= f;
	this->y /= f;
	this->z /= f;

	// 計算後の値を返還する
	return *this;
}

bool Vector3::operator==(const Vector3& v) const noexcept
{
	// 値が等しいか調べる
	return this->x == v.x && this->y == v.y && this->z == v.z;
}

bool Vector3::operator!=(const Vector3& v) const noexcept
{
	// 値の一致を調べる
	return this->x != v.x && this->y != v.y && this->z != v.z;
}

float Vector3::Dot(const Vector3& v) const noexcept
{
	// 内積を求める
	return (x * v.x) + (y * v.y) + (z * v.z);
}

float Vector3::Length() const noexcept
{
	// ベクトル長さを求める
	return std::sqrt(Dot(*this));
}

Vector3 Vector3::Cross(const Vector3& v) const noexcept
{
	// 結果格納用
	Vector3 result;

	// 値の計算を行う
	result.x = y * v.z - z * v.y;
	result.y = z * v.x - x * v.z;
	result.z = x * v.y - y * v.x;

	// 計算後の値を返す
	return result;
}

Vector3 Vector3::Normalize() const noexcept
{
	// ゼロベクトルだった場合そのまま返す
	if (*this == Vector3::kZero) {
		return *this;
	}

	// 計算を行う
	return *this / Length();
}

// 静的なメンバ関数の定義
const Vector3 Vector3::kZero = { 0.0f, 0.0f, 0.0f };
