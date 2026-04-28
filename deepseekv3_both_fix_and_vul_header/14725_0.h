#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef double TransformationMatrix_Matrix4[4][4];
typedef double Vector4[4];
typedef double Vector3[3];

namespace TransformationMatrix {
    struct DecomposedType {
        double perspectiveX;
        double perspectiveY;
        double perspectiveZ;
        double perspectiveW;
        double translateX;
        double translateY;
        double translateZ;
        double scaleX;
        double scaleY;
        double scaleZ;
        double skewXY;
        double skewXZ;
        double skewYZ;
        double quaternionX;
        double quaternionY;
        double quaternionZ;
        double quaternionW;
    };
    typedef double Matrix4[4][4];
}

static double determinant4x4(const TransformationMatrix::Matrix4& mat);
static bool inverse(const TransformationMatrix::Matrix4& mat, TransformationMatrix::Matrix4& result);
static void transposeMatrix4(const TransformationMatrix::Matrix4& mat, TransformationMatrix::Matrix4& result);
static void v4MulPointByMatrix(const Vector4& p, const TransformationMatrix::Matrix4& mat, Vector4& result);
static double v3Length(const Vector3& vec);
static void v3Scale(Vector3& vec, double scale);
static double v3Dot(const Vector3& a, const Vector3& b);
static void v3Combine(const Vector3& a, const Vector3& b, Vector3& result, double scaleA, double scaleB);
static void v3Cross(const Vector3& a, const Vector3& b, Vector3& result);