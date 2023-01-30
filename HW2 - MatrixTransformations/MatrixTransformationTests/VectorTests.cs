using MatrixTransformations;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace MatrixTransformationTests
{
    class VectorTests
    {


        public void Test_Vector_Construct()
        {
            Vector v = new Vector();

            Assert.AreEqual(v.x, 0);
            Assert.AreEqual(v.y, 0);
            Assert.AreEqual(v.z, 0);
            Assert.AreEqual(v.w, 0);
        }
        [TestCase(0, 0, 0, 0 )]
        [TestCase(10,4,10,4)]
        [TestCase(-9,-14,-9,-14)]
        [TestCase(-1,6,-1,6)]
        [TestCase(5,-9,5,-9)]
        public void Test_Vector_Construct_XY(float x, float y, float expectedX, float expectedY)
        {
            Vector v = new Vector(x,y);

            Assert.AreEqual(expectedX, v.x);
            Assert.AreEqual(expectedY, v.y);
            Assert.AreEqual(v.z, 0);
            Assert.AreEqual(v.w, 1);

        }
        [TestCase(0, 0, 0, 0, 0, 0)]
        [TestCase(12, 8, 4, 12, 8, 4)]
        [TestCase(-3, -8, -5, -3, -8, -5)]
        [TestCase(10,-3,4,10,-3,4)]
        [TestCase(-9,4,-6,-9,4,-6)]

        public void Test_Vector_Construct_XYZ(float x, float y, float z, float expectedX, float expectedY, float expectedZ)
        {
            Vector v = new Vector(x, y, z);
            Assert.AreEqual(expectedX, v.x);
            Assert.AreEqual(expectedY, v.y);
            Assert.AreEqual(expectedZ, v.z);
            Assert.AreEqual(v.w, 1);


        }
        [TestCase(0, 0, 0, 0, 0, 0, 0, 0)]
        [TestCase(10,3,7,8,10,3,7,8)]
        [TestCase(-5, -9, -4, -1, -5, -9, -4, -1)]
        [TestCase(10,-4, 0, -3, 10 ,-4 ,0 ,-3)]
        [TestCase(-3, 7, -4, 5, -3, 7, -4 ,5)]
        public void Test_Vector_Construct_XYZW(float x, float y, float z, float w, float expectedX, float expectedY, float expectedZ, float expectedW)
        {
            Vector v = new Vector(x, y, z, w);
            Assert.AreEqual(expectedX, v.x);
            Assert.AreEqual(expectedY, v.y);
            Assert.AreEqual(expectedZ, v.z);
            Assert.AreEqual(expectedW, v.w);
        }
               /* v1            v2      expected */  
        [TestCase(4,7,1,5,   10,7,3,3, 14,14,4,8)]
        [TestCase(-4,10,6,-1, 1,5,3,6, -3,15,9,5 )]
        public void Test_Vector_Plus_Operator(float v1x, float v1y, float v1z,float v1w, 
                                              float v2x, float v2y, float v2z, float v2w, 
                                              float ex, float ey,float ez, float ew)
        {
            Vector v1 = new Vector(v1x, v1y, v1z, v1w);
            Vector v2 = new Vector(v2x, v2y, v2z, v2w);
            Vector expected = new Vector(ex, ey, ez, ew);

            Vector v3 = v1 + v2;

            Assert.AreEqual(expected.x, v3.x);
            Assert.AreEqual(expected.y, v3.y);
            Assert.AreEqual(expected.z, v3.z);
            Assert.AreEqual(expected.w, v3.w);

            
        }
        [TestCase(10,9,8,7, 5,3,7,1, 5,6,1,6)]
        [TestCase(-5,6,50,2,4,30,1,4, -9,-24, 49, -2)]
        public void Test_Vector_Min_operator(float v1x, float v1y, float v1z, float v1w,
                                              float v2x, float v2y, float v2z, float v2w,
                                              float ex, float ey, float ez, float ew)
        {
            Vector v1 = new Vector(v1x, v1y, v1z, v1w);
            Vector v2 = new Vector(v2x, v2y, v2z, v2w);
            Vector expected = new Vector(ex, ey, ez, ew);

            Vector v3 = v1 - v2;

            Assert.AreEqual(expected.x, v3.x);
            Assert.AreEqual(expected.y, v3.y);
            Assert.AreEqual(expected.z, v3.z);
            Assert.AreEqual(expected.w, v3.w);
        }
        [TestCase(4,7,1,6, 3, 12,21,3,18)]
        [TestCase(10,4,1,6, 4, 40,16,4,24)]
        public void Test_Vector_Multiplication_VectorFloat(float v1x, float v1y, float v1z, float v1w,
                                                           float f,
                                                           float ex, float ey, float ez, float ew)
        {
            Vector v1 = new Vector(v1x, v1y, v1z, v1w);
            Vector expected = new Vector(ex, ey, ez, ew);

            Vector v3 = v1 * f;

            Assert.AreEqual(expected.x, v3.x);
            Assert.AreEqual(expected.y, v3.y);
            Assert.AreEqual(expected.z, v3.z);
            Assert.AreEqual(expected.w, v3.w);
        }
        [TestCase(10,3,1,6, 5, 50,15,5,30)]
        [TestCase(4,1,6,4, 2, 8,2,12,8)]
        public void Test_Vector_Multiplication_FloatVector(float v1x, float v1y, float v1z, float v1w,
                                                           float f,
                                                           float ex, float ey, float ez, float ew)
        {
            Vector v1 = new Vector(v1x, v1y, v1z, v1w);
            Vector expected = new Vector(ex, ey, ez, ew);

            Vector v3 = f * v1;

            Assert.AreEqual(expected.x, v3.x);
            Assert.AreEqual(expected.y, v3.y);
            Assert.AreEqual(expected.z, v3.z);
            Assert.AreEqual(expected.w, v3.w);
        }
    }
}
