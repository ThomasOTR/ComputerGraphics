using System;
using System.Text;

namespace MatrixTransformations
{
    public class Vector
    {
        public float x, y, z, w;

        public Vector(): this(0, 0, 0, 1) { }
        public Vector(float x, float y) : this(x, y, 0, 1) { }
        public Vector(float x, float y, float z) : this(x, y, z, 1){ }
        public Vector(float x, float y, float z, float w)
        {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = w;
        }

        public static Vector operator +(Vector v1, Vector v2)
        {
            Vector v3 = new Vector
            {
                x = v1.x + v2.x,
                y = v1.y + v2.y,
                z = v1.z + v2.z,
                w = v1.w + v2.w,
            };
            return v3;
        }
        public static Vector operator -(Vector v1, Vector v2)
        {
            Vector v3 = new Vector
            {
                x = v1.x - v2.x,
                y = v1.y - v2.y,
                z = v1.z - v2.z,
                w = v1.w - v2.w,
            };
            return v3;
        }
        public static Vector operator *(Vector v1, float f)
        {
            Vector v3 = new Vector
            {
                x = v1.x * f,
                y = v1.y * f,
                z = v1.z * f,
                w = v1.w * f,
            };
            return v3;
        }
        public static Vector operator *(float f, Vector v1)
        {
            Vector v = v1 * f;
            return v;
        }


        public override string ToString()
        {
           return $"x: {x} , y: {y} , z: {z} , w:{w}";
        }
    }
}
