using System;
using System.Text;

namespace MatrixTransformations
{
    public class Matrix
    {
        public float[,] mat = new float[4, 4];

        public Matrix()
        {
            mat[0, 0] = 1; mat[0, 1] = 0; mat[0, 2] = 0; mat[0, 3] = 0;
            mat[1, 0] = 0; mat[1, 1] = 1; mat[1, 2] = 0; mat[1, 3] = 0;
            mat[2, 0] = 0; mat[2, 1] = 0; mat[2, 2] = 1; mat[2, 3] = 0;
            mat[3, 0] = 0; mat[3, 1] = 0; mat[3, 2] = 0; mat[3, 3] = 1;
        }
        public Matrix(float m01, float m02, float m03, float m11, float m12, float m13, float m21, float m22, float m23)
        {
            mat[0, 0] = m01; mat[0, 1] = m02; mat[0, 2] = m03;
            mat[1, 0] = m11; mat[1, 1] = m12; mat[1, 2] = m13;
            mat[2, 0] = m21; mat[2, 1] = m22; mat[2, 2] = m23;

            mat[3, 3] = 1;

        }

        public Matrix(Vector v)
        {
            mat[0, 0] = v.x;
            mat[1, 0] = v.y;
            mat[2, 0] = v.z;
            mat[3, 0] = 1;

        }
        public static Matrix DefaultZeroMatrix()
        {
            Matrix matrix = new Matrix();
            matrix.mat[0, 0] = 0; matrix.mat[0, 1] = 0; matrix.mat[0, 2] = 0; matrix.mat[0, 3] = 0;
            matrix.mat[1, 0] = 0; matrix.mat[1, 1] = 0; matrix.mat[1, 2] = 0; matrix.mat[1, 3] = 0;
            matrix.mat[2, 0] = 0; matrix.mat[2, 1] = 0; matrix.mat[2, 2] = 0; matrix.mat[2, 3] = 0;
            matrix.mat[3, 0] = 0; matrix.mat[3, 1] = 0; matrix.mat[3, 2] = 0; matrix.mat[3, 3] = 0;
            return matrix;
        }

        public Vector ToVector()
        {
            return new Vector(mat[0, 0], mat[1, 0], mat[2, 0], mat[2, 0]);
        }

        public static Matrix operator +(Matrix m1, Matrix m2)
        {
            Matrix m = new Matrix();
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    m.mat[i, j] = m1.mat[i, j] + m2.mat[i, j];
                }
            }
            return m;
        }

        public static Matrix operator -(Matrix m1, Matrix m2)
        {
            Matrix m = new Matrix();
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    m.mat[i, j] = m1.mat[i, j] - m2.mat[i, j];
                }
            }
            return m;
        }

        public static Matrix operator *(Matrix m1, float f)
        {
            Matrix m = new Matrix();
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    m.mat[i, j] = m1.mat[i, j] * f;
                }
            }
            return m;
        }

        public static Matrix operator *(float f, Matrix m1)
        {
            Matrix m = new Matrix();
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    m.mat[i, j] = f * m1.mat[i, j];
                }
            }
            return m;
        }

        public static Matrix operator *(Matrix m1, Matrix m2)
        {
            Matrix m = DefaultZeroMatrix();
            for (int i = 0; i < m.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m.mat.GetLength(1); j++)
                {
                    m.mat[i, j] = 0;
                    for (int k = 0; k < m.mat.GetLength(1); k++)
                    {
                        m.mat[i, j] += m1.mat[i, k] * m2.mat[k, j];
                    }
                }
            }
            return m;
        }

        public static Vector operator *(Matrix m1, Vector v)
        {
            Matrix m = m1 * new Matrix(v);
            return m.ToVector();
        }

        public static Matrix Identity()
        {
            return new Matrix();
        }

        public override string ToString()
        {
            string output = "";
            for (int i = 0; i < mat.GetLength(0); i++)
            {
                for (int j = 0; j < mat.GetLength(1); j++)
                {
                    output += $"[{i},{j}]: {mat[i, j]} ";
                }
            }
            return output;
        }
        public static Matrix ScaleMatrix(float s)
        {
            Matrix m = new Matrix();
            m.mat[0, 0] = s;
            m.mat[1, 1] = s;
            m.mat[2, 2] = s;
            return m;
        }
        public static Matrix RotateXMatrix(float degrees)
        {
            double radians = (Math.PI / 180) * degrees;
            float cos = (float)Math.Cos(radians);
            float sin = (float)Math.Sin(radians);

            Matrix m = new Matrix();
            m.mat[1, 1] = cos;
            m.mat[1, 2] = -sin;
            m.mat[2, 1] = sin;
            m.mat[2, 2] = cos;

            return m;
        }
        public static Matrix RotateYMatrix(float degrees)
        {
            double radians = (Math.PI / 180) * degrees;
            float cos = (float)Math.Cos(radians);
            float sin = (float)Math.Sin(radians);
            Matrix m = new Matrix();
            m.mat[0, 0] = cos;
            m.mat[0, 2] = sin;
            m.mat[2, 0] = -sin;
            m.mat[2, 2] = cos;

            return m;
        }
        public static Matrix RotateZMatrix(float degrees)
        {
            double radians = (Math.PI / 180) * degrees;
            float cos = (float)Math.Cos(radians);
            float sin = (float)Math.Sin(radians);
            Matrix m = new Matrix();
            m.mat[0, 0] = cos;
            m.mat[0, 1] = -sin;
            m.mat[1, 0] = sin;
            m.mat[1, 1] = cos;

            return m;
        }
        public static Matrix TranslateMatrix(Vector v)
        {
            Matrix m = new Matrix();

            m.mat[0, 3] = v.x;
            m.mat[1, 3] = v.y;
            m.mat[2, 3] = v.z;

            return m;

        }
        public static Matrix ViewMatrix(float r, float phi, float theta)
        {
            float thetarad = theta * (float)Math.PI / 180;
            float phirad = phi * (float)Math.PI / 180;

            float cos_theta = (float)Math.Cos(thetarad);
            float sin_theta = (float)Math.Sin(thetarad);
            float cos_phi = (float)Math.Cos(phirad);
            float sin_phi = (float)Math.Sin(phirad);

            Matrix m = new Matrix();

            m.mat[0, 0] = -sin_theta;
            m.mat[0, 1] = cos_theta;

            m.mat[1, 0] = -cos_theta * cos_phi;
            m.mat[1, 1] = -cos_phi * sin_theta;
            m.mat[1, 2] = sin_phi;

            m.mat[2, 0] = cos_theta * sin_phi;
            m.mat[2, 1] = sin_theta * sin_phi;
            m.mat[2, 2] = cos_phi;
            m.mat[2, 3] = -r;

            return m;
        }
        public static Matrix ProjectionMatrix(float d, float z)
        {
            Matrix m = new Matrix();
            float f = -(d / z);
            m.mat[0, 0] = f; m.mat[1, 1] = f;
            return m;
        }

    }
}
