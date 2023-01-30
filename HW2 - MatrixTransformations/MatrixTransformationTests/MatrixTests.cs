using MatrixTransformations;
using NUnit.Framework;
using System;
namespace MatrixTransformationTests
{
    public class MatrixTests
    {
        [Test]
        public void Test_Matrix_constructor_identity()
        {
            Matrix m1 = new Matrix();
            bool isIdentity = true;
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    if (i == j && m1.mat[i, j] != 1) isIdentity = false;
                    else if (i != j && m1.mat[i, j] != 0) isIdentity = false;
                }
            }
            Assert.IsTrue(isIdentity);
        }
        [TestCase(1,2,3,4,5,6,7,8,9)]
        [TestCase(4,-5,2,-3,1,-7,1,0,4)]
        public void Test_Matrix_constructor_parameters(float m01, float m02, float m03, float m11, float m12, float m13, float m21, float m22, float m23)
        {
            Matrix m = new Matrix(m01, m02, m03, m11, m12, m13, m21, m22, m23);
            Assert.AreEqual(m01, m.mat[0, 0]);
            Assert.AreEqual(m02, m.mat[0, 1]);
            Assert.AreEqual(m03, m.mat[0, 2]);

            Assert.AreEqual(m11, m.mat[1, 0]);
            Assert.AreEqual(m12, m.mat[1, 1]);
            Assert.AreEqual(m13, m.mat[1, 2]);

            Assert.AreEqual(m21, m.mat[2, 0]);
            Assert.AreEqual(m22, m.mat[2, 1]);
            Assert.AreEqual(m23, m.mat[2, 2]);
        }
        [TestCase(0, 0, 0)]
        [TestCase(1, 2, 3)]
        [TestCase(-1, -3, 5)]
        public void Test_Matrix_constructor_vector(float vx,float vy,float vz)
        {
            Vector v = new Vector(vx, vy, vz);
            Matrix m = new Matrix(v);
            Assert.AreEqual(v.x, m.mat[0, 0]);
            Assert.AreEqual(v.y, m.mat[1, 0]);
            Assert.AreEqual(v.z, m.mat[2, 0]);
            Assert.AreEqual(v.w, 1);
        }
        [Test]
        public void Test_Matrix_ZeroMatrix()
        {
            Matrix m1 = Matrix.DefaultZeroMatrix();
            bool ZeroIsTrue = true;
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    if (m1.mat[i, j] != 0) ZeroIsTrue = false;
                }
            }
            Assert.IsTrue(ZeroIsTrue);
        }
        [TestCase(0, 0, 0)]
        [TestCase(1, 2, 3)]
        [TestCase(-1, -3, 5)]
        public void Test_Matrix_ToVector(float vx, float vy, float vz)
        {
            Vector v = new Vector(vx, vy, vz);
            Matrix m = new Matrix(v);
            Vector v2 = m.ToVector();

            Assert.AreEqual(vx, v2.x);
            Assert.AreEqual(vy, v2.y);
            Assert.AreEqual(vz, v2.z);
            Assert.AreEqual(vz, v2.w);
        }
        [TestCaseSource("MatrixInput")]
        public void Test_Matrix_Plus_Operator(Matrix m1, Matrix m2)
        {
            Matrix m3 = m1 + m2;
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    Assert.AreEqual(m1.mat[i, j] + m2.mat[i, j], m3.mat[i, j]);
                }
            }
        }
        [TestCaseSource("MatrixInput")]
        public void Test_Matrix_Min_Operator(Matrix m1, Matrix m2)
        {
            Matrix m3 = m1 - m2;
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    Assert.AreEqual(m1.mat[i, j] - m2.mat[i, j], m3.mat[i, j]);
                }
            }
        }
        [TestCaseSource("MatrixFloatInput")]
        public void Test_Matrix_Multiplication_Operator_FloatMatrix(Matrix m1, float f)
        {
            Matrix m3 = f * m1;
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    Assert.AreEqual(f* m1.mat[i,j], m3.mat[i, j]);
                }
            }
        }
        [TestCaseSource("MatrixFloatInput")]
        public void Test_Matrix_Multiplication_Operator_MatrixFloat(Matrix m1, float f)
        {
            Matrix m3 = m1 * f;
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    Assert.AreEqual(m1.mat[i, j] * f, m3.mat[i, j]);
                }
            }
        }

        private static readonly object[] MatrixInput =
          {
            new object[]{ new Matrix(10,4,1,5,3,6,3,5,3), new Matrix(50,3,1,5,3,7,3,7,3)},
            new object[]{ new Matrix(4,4,6,3,7,3,8,5,4), new Matrix(-3,4,2,4,-1,4,-4,9,0)},
            new object[]{ new Matrix(10,3,1,7,4,-4,-3,3,0), new Matrix(19,3,6,8,4,3,5,-5,2)},
          };
        private static readonly object[] MatrixFloatInput =
        {
            new object[]{ new Matrix(10,4,6,3,6,32,8,3,8), 3.0f},
            new object[]{ new Matrix(5,3,7,1,-5,3,6,-1,0), 2.0f},
            new object[]{ new Matrix(10,3,1,5,3,45,2,-1,-1),5.0f },
        };

        [TestCase(5)]
        [TestCase(3)]
        [TestCase(2)]
        public void Test_Matrix_ScaleMatrix(float s)
        {
            Matrix m1 = Matrix.ScaleMatrix(s);
            bool isScale = true;
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    if (i == j && m1.mat[i, j] != s && i < 3) isScale = false;
                    else if (i != j && m1.mat[i, j] != 0) isScale = false;
                }
            }
            Assert.IsTrue(isScale);
        }
        [TestCase(30)]
        [TestCase(3)]
        [TestCase(25)]
        public void Test_Matrix_RotateXMatrix(float degrees)
        {
            double radians = (Math.PI / 180) * degrees;
            float cos = (float)Math.Cos(radians);
            float sin = (float)Math.Sin(radians);

            Matrix m = Matrix.RotateXMatrix(degrees);
            Assert.AreEqual(cos, m.mat[1, 1]);
            Assert.AreEqual(-sin,m.mat[1, 2]);
            Assert.AreEqual(sin, m.mat[2, 1]);
            Assert.AreEqual(cos, m.mat[2, 2]);
        }
        [TestCase(2)]
        [TestCase(30)]
        [TestCase(10)]
        public void Test_Matrix_RotateYMatrix(float degrees)
        {
            double radians = (Math.PI / 180) * degrees;
            float cos = (float)Math.Cos(radians);
            float sin = (float)Math.Sin(radians);
            Matrix m = Matrix.RotateYMatrix(degrees);
            Assert.AreEqual(cos, m.mat[0, 0]);
            Assert.AreEqual(sin, m.mat[0, 2]);
            Assert.AreEqual(-sin, m.mat[2, 0]);
            Assert.AreEqual(cos, m.mat[2, 2]);
        }
        [TestCase(30)]
        [TestCase(5)]
        [TestCase(20)]
        public void Test_Matrix_RotateZMatrix(float degrees)
        {
            double radians = (Math.PI / 180) * degrees;
            float cos = (float)Math.Cos(radians);
            float sin = (float)Math.Sin(radians);
            Matrix m = Matrix.RotateZMatrix(degrees);
            Assert.AreEqual(cos, m.mat[0, 0]);
            Assert.AreEqual(-sin, m.mat[0, 1]);
            Assert.AreEqual(sin, m.mat[1, 0]);
            Assert.AreEqual(cos, m.mat[1, 1]);
        }
        [TestCase(1,3,4)]
        [TestCase(5,3,1)]
        [TestCase(-1,-4,4)]
        public void Test_Matrix_TranslateMatrix(float vx, float vy, float vz)
        {
            Vector v = new Vector(vx, vy, vz);
            Matrix m = Matrix.TranslateMatrix(v);

            Assert.AreEqual(m.mat[0, 3], v.x);
            Assert.AreEqual(m.mat[1, 3], v.y);
            Assert.AreEqual(m.mat[2, 3], v.z);
        }
        [TestCase(4,3,3)]
        [TestCase(3,1,5)]
        [TestCase(-1,2,-5)]
        public void Test_Matrix_ViewMatrix(float r, float phi, float theta)
        {
            float thetarad = theta * (float)Math.PI / 180;
            float phirad = phi * (float)Math.PI / 180;

            float cos_theta = (float)Math.Cos(thetarad);
            float sin_theta = (float)Math.Sin(thetarad);
            float cos_phi = (float)Math.Cos(phirad);
            float sin_phi = (float)Math.Sin(phirad);

            Matrix m = Matrix.ViewMatrix(r,phi,theta);

            Assert.AreEqual(-sin_theta, m.mat[0, 0]);
            Assert.AreEqual(cos_theta, m.mat[0, 1]);

            Assert.AreEqual(-cos_theta * cos_phi, m.mat[1, 0]);
            Assert.AreEqual(-cos_phi * sin_theta, m.mat[1, 1]);
            Assert.AreEqual(sin_phi, m.mat[1, 2]);

            Assert.AreEqual(cos_theta * sin_phi,m.mat[2, 0]);
            Assert.AreEqual(sin_theta * sin_phi,m.mat[2, 1]);
            Assert.AreEqual(cos_phi, m.mat[2, 2]);
            Assert.AreEqual(-r, m.mat[2, 3]);
        }


        [TestCase(10,5)]
        [TestCase(-4,1)]
        [TestCase(5,-5)]
        [TestCase(-4,-9)]
        public void Test_Matrix_ProjectionMatrix(float d, float z)
        {
            float f = -(d / z);
            Matrix m = Matrix.ProjectionMatrix(d,z);

            Assert.AreEqual(f, m.mat[0, 0]);
            Assert.AreEqual(f, m.mat[1, 1]);

        }
    }
}