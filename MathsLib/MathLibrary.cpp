#include "stdafx.h"
#include "MathLibrary.h"
#include <math.h>
#include <assert.h>  

vec2::vec2()
{
	m_X = 0;
	m_Y = 0;
}

vec2::vec2(float a_X, float a_Y)
{
	//a vector has a direction and a magnitude.
	//structs should define minimal functionality/behaviour
	//union: a way to define multiple structures of data and store it all in the same memory
	m_X = a_X;
	m_Y = a_Y;
}

vec2 & vec2::operator=(const vec2 & rhs)
{
	m_X = rhs.m_X;
	m_Y = rhs.m_Y;
	return *this;
}

vec2 & vec2::operator+=(const vec2 & a_Rhs)
{
	*this = *this + a_Rhs;
	return *this;
}

vec2 & vec2::operator-=(const vec2 & a_Rhs)
{
	*this = *this - a_Rhs;
	return *this;
}

vec2 & vec2::operator*=(float a_Rhs)
{
	*this = *this * a_Rhs;
	return *this;
}

vec2 & vec2::operator/=(float a_Rhs)
{
	*this = *this / a_Rhs;
	return *this;
}

float vec2::operator[](int a_Index) const
{
	assert(a_Index < 2 && a_Index > 0);
	return v[a_Index];
}

float & vec2::operator[](int a_Index)
{
	assert(a_Index < 2 && a_Index > 0);
	return v[a_Index];
}

vec2 & vec2::normalize()
{
	float mag = length();
	float inv = 1 / mag;
	m_X *= inv;
	m_Y *= inv;
	return *this;
}

vec2 operator+(const vec2 & a_Lhs, const vec2 & a_Rhs)
{
	return vec2(a_Lhs.m_X + a_Rhs.m_X, a_Lhs.m_Y + a_Rhs.m_Y);
}

vec2 operator-(const vec2 & a_Lhs, const vec2 & a_Rhs)
{
	return vec2(a_Lhs.m_X - a_Rhs.m_X, a_Lhs.m_Y - a_Rhs.m_Y);
}

vec2 operator*(const vec2 & a_Lhs, float a_Rhs)
{
	return vec2(a_Lhs.m_X * a_Rhs, a_Lhs.m_Y * a_Rhs);
}

vec2 operator/(const vec2 & a_Lhs, float a_Rhs)
{
	return vec2(a_Lhs.m_X / a_Rhs, a_Lhs.m_Y / a_Rhs);
}

bool operator==(const vec2 & a_Lhs, const vec2 & a_Rhs)
{
	return
		(a_Lhs.m_X == a_Rhs.m_X) &&
		(a_Lhs.m_Y == a_Rhs.m_Y);
}

bool operator!=(const vec2 & a_Lhs, const vec2 & a_Rhs)
{
	return !(a_Lhs == a_Rhs);
}

vec3 operator+(const vec3 & a_Lhs, const vec3 & a_Rhs)
{
	return vec3(a_Lhs.m_X + a_Rhs.m_X, a_Lhs.m_Y + a_Rhs.m_Y, a_Lhs.m_Z + a_Rhs.m_Z);
}

vec3 operator-(const vec3 & a_Lhs, const vec3 & a_Rhs)
{
	return vec3(a_Lhs.m_X - a_Rhs.m_X, a_Lhs.m_Y - a_Rhs.m_Y, a_Lhs.m_Z - a_Rhs.m_Z);
}

vec3 operator*(const vec3 & a_Lhs, float a_Rhs)
{
	return vec3(a_Lhs.m_X * a_Rhs, a_Lhs.m_Y * a_Rhs, a_Lhs.m_Z * a_Rhs);
}

vec3 operator*(const vec3 & a_Lhs, const vec3 & a_Rhs)
{
	return vec3(a_Lhs.m_X * a_Rhs.m_X, a_Lhs.m_Y * a_Rhs.m_Y, a_Lhs.m_Z * a_Rhs.m_Z);
}

vec3 operator/(const vec3 & a_Lhs, float a_Rhs)
{
	return vec3(a_Lhs.m_X / a_Rhs, a_Lhs.m_Y / a_Rhs, a_Lhs.m_Z / a_Rhs);
}

bool operator==(const vec3 & a_Lhs, const vec3 & a_Rhs)
{
	return
		(a_Lhs.m_X == a_Rhs.m_X) &&
		(a_Lhs.m_Y == a_Rhs.m_Y) &&
		(a_Lhs.m_Z == a_Rhs.m_Z);
};

bool operator!=(const vec3 & a_Lhs, const vec3 & a_Rhs)
{
	return
		!(a_Lhs == a_Rhs);
}

vec3::vec3()
{
	m_X = 0;
	m_Y = 0;
	m_Z = 0;
}

vec3::vec3(float a_X, float a_Y, float a_Z)
{
	m_X = a_X;
	m_Y = a_Y;
	m_Z = a_Z;
}

vec3 & vec3::operator=(const vec3 & rhs)
{
	m_X = rhs.m_X;
	m_Y = rhs.m_Y;
	m_Z = rhs.m_Z;
	return *this;
}

vec3 & vec3::operator+=(const vec3 & a_Rhs)
{
	*this = *this + a_Rhs;
	return *this;
}

vec3 & vec3::operator-=(const vec3 & a_Rhs)
{
	*this = *this - a_Rhs;
	return *this;
}

vec3 & vec3::operator*=(float a_Rhs)
{
	*this = *this * a_Rhs;

	return *this;
}

vec3 & vec3::operator/=(float a_Rhs)
{
	*this = *this / a_Rhs;
	return *this;
}

float vec3::operator[](int a_Index) const
{
	assert(a_Index < 3 && a_Index > 0);
	return v[a_Index];
}

float & vec3::operator[](int a_Index)
{
	//assert(a_Index < 3 && a_Index > 0);
	return v[a_Index];
}

vec3 & vec3::normalize()
{
	float mag = length();
	float inv = 1 / mag;
	m_X *= inv;
	m_Y *= inv;
	m_Z *= inv;
	return *this;
}

vec3 vec3::invert() const
{
	return vec3(-m_X, -m_Y, -m_Z);
}

mat4 operator+(const mat4 & a_Lhs, const mat4 & a_Rhs)
{
	mat4 addition;
	for (int matRow = 0; matRow < 4; matRow++)
	{
		for (int matColumn = 0; matColumn < 4; matColumn++)
		{
			addition.mat[matRow][matColumn] = a_Lhs.mat[matRow][matColumn] + a_Rhs.mat[matRow][matColumn];
		}
	}
	return addition;
}

mat4 operator-(const mat4 & a_Lhs, const mat4 & a_Rhs)
{
	mat4 subtraction;
	for (int matRow = 0; matRow < 4; matRow++)
	{
		for (int matColumn = 0; matColumn < 4; matColumn++)
		{
			subtraction.mat[matRow][matColumn] = a_Lhs.mat[matRow][matColumn] - a_Rhs.mat[matRow][matColumn];
		}
	}
	return subtraction;
}

mat4 operator*(const mat4 & a_Lhs, const mat4 & a_Rhs)
{
	mat4 multiplied;
	for (int matRow = 0; matRow < 4; matRow++)
	{
		for (int matColumn = 0; matColumn < 4; matColumn++)
		{
			vec3 row = vec3(a_Lhs.mat[matRow][0], a_Lhs.mat[matRow][1], a_Lhs.mat[matRow][2]);
			vec3 column = vec3(a_Rhs.mat[0][matColumn], a_Rhs.mat[1][matColumn], a_Rhs.mat[2][matColumn]);
			float dot = row.dot(column) + (a_Lhs.mat[matRow][3] * a_Rhs.mat[3][matColumn]);
			multiplied.mat[matRow][matColumn] = dot;
		}
	}
	return multiplied;
}


mat4::mat4()
{
	for (int i = 0; i < 16; i++)
	{
		m[i] = 0;
	}
}

mat4::mat4(vec3 a_Row0, float a_03, vec3 a_Row1, float a_13, vec3 a_Row2, float a_23, vec3 a_Row3, float a_33)
{
	m_00 = a_Row0.m_X;
	m_01 = a_Row0.m_Y;
	m_02 = a_Row0.m_Z;
	m_03 = a_03;

	m_10 = a_Row1.m_X;
	m_11 = a_Row1.m_Y;
	m_12 = a_Row1.m_Z;
	m_13 = a_13;

	m_20 = a_Row2.m_X;
	m_21 = a_Row2.m_Y;
	m_22 = a_Row2.m_Z;
	m_23 = a_23;

	m_30 = a_Row3.m_X;
	m_31 = a_Row3.m_Y;
	m_32 = a_Row3.m_Z;
	m_33 = a_33;
}

mat4::mat4(float a_00, float a_01, float a_02, float a_03, float a_10, float a_11, float a_12, float a_13, float a_20, float a_21, float a_22, float a_23, float a_30, float a_31, float a_32, float a_33)
{
	m_00 = a_00;
	m_01 = a_01;
	m_02 = a_02;
	m_03 = a_03;
	m_10 = a_10;
	m_11 = a_11;
	m_12 = a_12;
	m_13 = a_13;
	m_20 = a_20;
	m_21 = a_21;
	m_22 = a_22;
	m_23 = a_23;
	m_30 = a_30;
	m_31 = a_31;
	m_32 = a_32;
	m_33 = a_33;
}

mat4 & mat4::operator=(const mat4 & rhs)
{
	for (int matRow = 0; matRow < 4; matRow++)
	{
		for (int matColumn = 0; matColumn < 4; matColumn++)
		{
			mat[matRow][matColumn] = rhs.mat[matRow][matColumn];
		}
	}
	return *this;
}

mat4 & mat4::operator+=(const mat4 & a_Rhs)
{
	*this = *this + a_Rhs;
	return *this;
}

mat4 & mat4::operator-=(const mat4 & a_Rhs)
{
	*this = *this - a_Rhs;
	return *this;
}

mat4 & mat4::operator*=(const mat4 & a_Rhs)
{
	*this = *this * a_Rhs;
	return *this;
}

std::ostream & operator<<(std::ostream & a_Lhs, const mat4 & a_Rhs)
{
	a_Lhs << a_Rhs.m[0] << " " << a_Rhs.m[1] << " " << a_Rhs.m[2] << " " << a_Rhs.m[3] << std::endl
		<< a_Rhs.m[4] << " " << a_Rhs.m[5] << " " << a_Rhs.m[6] << " " << a_Rhs.m[7] << std::endl
		<< a_Rhs.m[8] << " " << a_Rhs.m[9] << " " << a_Rhs.m[10] << " " << a_Rhs.m[11] << std::endl
		<< a_Rhs.m[12] << " " << a_Rhs.m[13] << " " << a_Rhs.m[14] << " " << a_Rhs.m[15];
	return a_Lhs;
}

float mat4::determinant() const
{
	float determinants[4];

	//Loop through mat4 columns & find the determinant of each 3x3 sub matrix
	for (int i = 0; i < 4; i++)
	{
		float mat3[3][3];
		for (int matRow = 0; matRow < 3; matRow++)
		{
			for (int matColumn = 0; matColumn < 3; matColumn++)
			{
				//Find the 4x4matrix column to use for the 3x3 submatrix
				int column = i + 1 + matColumn;
				if (column > 3)
				{
					column -= 4;
				}
				
				mat3[matRow][matColumn] = mat[matRow +1][column];
			}
		}
		
		//matrix3 has been constructed, find determinant
		determinants[i] =
			(mat3[0][0] * ((mat3[1][1] * mat3[2][2]) - (mat3[1][2] * mat3[2][1]))) - //3x3 Determinant A
			(mat3[0][1] * ((mat3[1][0] * mat3[2][2]) - (mat3[1][2] * mat3[2][0]))) + //3x3 Determinant B
			(mat3[0][2] * ((mat3[1][0] * mat3[2][1]) - (mat3[1][1] * mat3[2][0])));  //3x3 Determinant C
	}
	//find 4x4 determinant & return
	return mat[0][0] * determinants[0] - mat[0][1] * determinants[1] + mat[0][2] * determinants[2] - mat[0][3] * determinants[3];
}

mat4 & mat4::inverse()
{
	float inv[16];

	inv[0] = m[5] * m[10] * m[15] -
		m[5] * m[11] * m[14] -
		m[9] * m[6] * m[15] +
		m[9] * m[7] * m[14] +
		m[13] * m[6] * m[11] -
		m[13] * m[7] * m[10];

	inv[4] = -m[4] * m[10] * m[15] +
		m[4] * m[11] * m[14] +
		m[8] * m[6] * m[15] -
		m[8] * m[7] * m[14] -
		m[12] * m[6] * m[11] +
		m[12] * m[7] * m[10];

	inv[8] = m[4] * m[9] * m[15] -
		m[4] * m[11] * m[13] -
		m[8] * m[5] * m[15] +
		m[8] * m[7] * m[13] +
		m[12] * m[5] * m[11] -
		m[12] * m[7] * m[9];

	inv[12] = -m[4] * m[9] * m[14] +
		m[4] * m[10] * m[13] +
		m[8] * m[5] * m[14] -
		m[8] * m[6] * m[13] -
		m[12] * m[5] * m[10] +
		m[12] * m[6] * m[9];

	inv[1] = -m[1] * m[10] * m[15] +
		m[1] * m[11] * m[14] +
		m[9] * m[2] * m[15] -
		m[9] * m[3] * m[14] -
		m[13] * m[2] * m[11] +
		m[13] * m[3] * m[10];

	inv[5] = m[0] * m[10] * m[15] -
		m[0] * m[11] * m[14] -
		m[8] * m[2] * m[15] +
		m[8] * m[3] * m[14] +
		m[12] * m[2] * m[11] -
		m[12] * m[3] * m[10];

	inv[9] = -m[0] * m[9] * m[15] +
		m[0] * m[11] * m[13] +
		m[8] * m[1] * m[15] -
		m[8] * m[3] * m[13] -
		m[12] * m[1] * m[11] +
		m[12] * m[3] * m[9];

	inv[13] = m[0] * m[9] * m[14] -
		m[0] * m[10] * m[13] -
		m[8] * m[1] * m[14] +
		m[8] * m[2] * m[13] +
		m[12] * m[1] * m[10] -
		m[12] * m[2] * m[9];

	inv[2] = m[1] * m[6] * m[15] -
		m[1] * m[7] * m[14] -
		m[5] * m[2] * m[15] +
		m[5] * m[3] * m[14] +
		m[13] * m[2] * m[7] -
		m[13] * m[3] * m[6];

	inv[6] = -m[0] * m[6] * m[15] +
		m[0] * m[7] * m[14] +
		m[4] * m[2] * m[15] -
		m[4] * m[3] * m[14] -
		m[12] * m[2] * m[7] +
		m[12] * m[3] * m[6];

	inv[10] = m[0] * m[5] * m[15] -
		m[0] * m[7] * m[13] -
		m[4] * m[1] * m[15] +
		m[4] * m[3] * m[13] +
		m[12] * m[1] * m[7] -
		m[12] * m[3] * m[5];

	inv[14] = -m[0] * m[5] * m[14] +
		m[0] * m[6] * m[13] +
		m[4] * m[1] * m[14] -
		m[4] * m[2] * m[13] -
		m[12] * m[1] * m[6] +
		m[12] * m[2] * m[5];

	inv[3] = -m[1] * m[6] * m[11] +
		m[1] * m[7] * m[10] +
		m[5] * m[2] * m[11] -
		m[5] * m[3] * m[10] -
		m[9] * m[2] * m[7] +
		m[9] * m[3] * m[6];

	inv[7] = m[0] * m[6] * m[11] -
		m[0] * m[7] * m[10] -
		m[4] * m[2] * m[11] +
		m[4] * m[3] * m[10] +
		m[8] * m[2] * m[7] -
		m[8] * m[3] * m[6];

	inv[11] = -m[0] * m[5] * m[11] +
		m[0] * m[7] * m[9] +
		m[4] * m[1] * m[11] -
		m[4] * m[3] * m[9] -
		m[8] * m[1] * m[7] +
		m[8] * m[3] * m[5];

	inv[15] = m[0] * m[5] * m[10] -
		m[0] * m[6] * m[9] -
		m[4] * m[1] * m[10] +
		m[4] * m[2] * m[9] +
		m[8] * m[1] * m[6] -
		m[8] * m[2] * m[5];

	const float det = 1.0f / (m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12]);

	for (int i = 0; i < 16; i++)
		m[i] = inv[i] * det;

	return *this;
}

mat4 mat4::identity()
{
	return mat4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
}

mat4 mat4::rotateX(float a_Radians)
{
	mat4 rotMatrix = identity();
	rotMatrix.mat[1][1] = cos(a_Radians);
	rotMatrix.mat[2][2] = cos(a_Radians);
	rotMatrix.mat[1][2] = -sin(a_Radians);
	rotMatrix.mat[2][1] = sin(a_Radians);

	return rotMatrix;
}

mat4 mat4::rotateY(float a_Radians)
{
	mat4 rotMatrix = identity();
	rotMatrix.mat[0][0] = cos(a_Radians);
	rotMatrix.mat[2][2] = cos(a_Radians);
	rotMatrix.mat[2][0] = -sin(a_Radians);
	rotMatrix.mat[0][2] = sin(a_Radians);
	
	return rotMatrix;
}

mat4 mat4::rotateZ(float a_Radians)
{
	mat4 rotMatrix = identity();
	rotMatrix.mat[0][0] = cos(a_Radians);
	rotMatrix.mat[1][1] = cos(a_Radians);
	rotMatrix.mat[0][1] = -sin(a_Radians);
	rotMatrix.mat[1][0] = sin(a_Radians);

	return rotMatrix;
}

mat4 mat4::translate(const vec3 & a_Translation)
{
	mat4 transMatrix = identity();
	transMatrix.mat[3][0] = a_Translation.m_X;
	transMatrix.mat[3][1] = a_Translation.m_Y;
	transMatrix.mat[3][2] = a_Translation.m_Z;
	return transMatrix;
}

mat4 mat4::lookat(const vec3 & a_Eye, const vec3 & a_Center, const vec3 & a_Up)
{
	return mat4();
	a_Eye;
	a_Center;
	a_Up;
}

mat4 mat4::projection(float a_FovY, float a_AspectRatio, float a_Near, float a_Far)
{
	return mat4();
	a_FovY;
	a_AspectRatio;
	a_Near;
	a_Far;
}

vec3 operator*(const mat4 & a_Lhs, const vec3 & a_Rhs)
{
	vec3 multiplied;
	for (int matRow = 0; matRow < 3; matRow++)
	{
		vec3 row = vec3(a_Lhs.mat[matRow][0], a_Lhs.mat[matRow][1], a_Lhs.mat[matRow][2]);
		float dot = row.dot(a_Rhs);
		multiplied[matRow] = dot;
	}
	return multiplied;
}