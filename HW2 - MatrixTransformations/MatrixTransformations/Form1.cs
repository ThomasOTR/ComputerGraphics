using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.Timers;

namespace MatrixTransformations
{
    public partial class Form1 : Form
    {
        AxisX x_axis;
        AxisY y_axis;
        AxisZ z_axis;

        Cube cube;

        float scale = 1.0f;
        Vector translate = new Vector(0.0f, 0.0f, 0.0f);
        Vector rotate = new Vector(0.0f, 0.0f, 0.0f);

        float d = 800.0f;
        float r = 10.0f;
        float phi = -10.0f;
        float theta = -100.0f;

        Matrix scaleMatrix, rotationMatrix, translationMatrix, transformationMatrix;

        System.Timers.Timer timer;

        // Window dimensions
        const int WIDTH = 800;
        const int HEIGHT = 600;

        public Form1()
        {
            InitializeComponent();

            this.Width = WIDTH;
            this.Height = HEIGHT;
            this.DoubleBuffered = true;

            // Define axis.
            x_axis = new AxisX(1);
            y_axis = new AxisY(1);
            z_axis = new AxisZ(1);

            cube = new Cube(Color.Orange);

            // Timer for animation.
            timer = new System.Timers.Timer(50);
            timer.Elapsed += Animation;
        }
        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            /* Update Labels */
            lblScale.Text = scale.ToString();
            lblTransX.Text = translate.x.ToString();
            lblTransY.Text = translate.y.ToString();
            lblTransZ.Text = translate.z.ToString();

            lblRotX.Text = rotate.x.ToString();
            lblRotY.Text = rotate.y.ToString();
            lblRotZ.Text = rotate.z.ToString();

            lblR.Text = r.ToString();
            lblD.Text = d.ToString();
            lblPhi.Text = phi.ToString();
            lblTheta.Text = theta.ToString();

            lblPhase.Text = animation.ToString();


            /* Create TransformationMatrix */
            scaleMatrix = Matrix.ScaleMatrix(scale);
            rotationMatrix = Matrix.RotateXMatrix(rotate.x) * Matrix.RotateYMatrix(rotate.y) * Matrix.RotateZMatrix(rotate.z);
            translationMatrix = Matrix.TranslateMatrix(translate);

            transformationMatrix = translationMatrix * rotationMatrix * scaleMatrix;

            /* Draw axes */
            x_axis.Draw(e.Graphics, ViewingPipeline(new Matrix(), x_axis.vb));
            y_axis.Draw(e.Graphics, ViewingPipeline(new Matrix(), y_axis.vb));
            z_axis.Draw(e.Graphics, ViewingPipeline(new Matrix(), z_axis.vb));

            /* Draw Cube */
            cube.Draw(e.Graphics, ViewingPipeline(transformationMatrix, cube.vertexbuffer));
        }

        public static List<Vector> ViewPortTransformation(List<Vector> vb)
        {
            float delta_x = WIDTH / 2;
            float delta_y = HEIGHT / 2;
            List<Vector> result = new List<Vector>();
            foreach (Vector v in vb)
            {
                float x = v.x + delta_x;
                float y = delta_y - v.y;
                result.Add(new Vector(x, y));
            }
            return result;
        }

        public List<Vector> ViewingPipeline(Matrix T, List<Vector> vb)
        {
            Matrix view = Matrix.ViewMatrix(r, phi, theta);
            List<Vector> result = new List<Vector>();
            Vector v2;
            foreach (Vector v in vb)
            {
                /* Model Transformation */
                v2 = T * v;
                /* View Transformation */
                v2 = view * v2;
                /* Projection Transformation */
                v2 = Matrix.ProjectionMatrix(d, v2.z) * v2;

                result.Add(v2);
            }
            return ViewPortTransformation(result);
        }

        private enum animation_phase
        {
            Phase1_start,
            Phase1_stop,
            Phase2_start,
            Phase2_stop,
            Phase3_start,
            Phase3_stop,
            Phase4,
        }
        private animation_phase animation = animation_phase.Phase1_start;

        public void Animation(object sender, ElapsedEventArgs e)
        {
            switch (animation)
            {
                // Phase 1.
                case animation_phase.Phase1_start:
                    if (scale < 1.5f)
                    {
                        scale += 0.01f;
                        theta -= 1.0f;
                    }
                    else animation = animation_phase.Phase1_stop;
                    break;
                case animation_phase.Phase1_stop:
                    if (scale > 1.0f)
                    {
                        scale -= 0.01f;
                        theta -= 1.0f;
                    }
                    else animation = animation_phase.Phase2_start;
                    break;
                // Phase 2.
                case animation_phase.Phase2_start:
                    if (rotate.x < 45.0f)
                    {
                        rotate.x += 1.0f;
                        theta -= 1.0f;
                    }
                    else animation = animation_phase.Phase2_stop;
                    break;
                case animation_phase.Phase2_stop:
                    if (rotate.x > 0.0f)
                    {
                        rotate.x -= 1.0f;
                        theta -= 1.0f;
                    }
                    else animation = animation_phase.Phase3_start;
                    break;
                // Phase 3.
                case animation_phase.Phase3_start:
                    if (rotate.y < 45.0f)
                    {
                        rotate.y += 1.0f;
                        phi += 1.0f;
                    }
                    else animation = animation_phase.Phase3_stop;
                    break;
                case animation_phase.Phase3_stop:
                    if (rotate.y > 0.0f)
                    {
                        rotate.y -= 1.0f;
                        phi += 1.0f;
                    }
                    else animation = animation_phase.Phase4;
                    break;
                // Phase 4 (extra to reset animation)
                case animation_phase.Phase4:
                    if (theta < -100.0f) theta += 1.0f;
                    if (phi > -10.0f) phi -= 1.0f;
                    if (theta == -100.0f && phi == -10.0f) animation = animation_phase.Phase1_start;
                    break;
                default:
                    break;
            }
            /* Refresh display */
            Invalidate();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Escape:
                    Application.Exit();
                    break;
                case Keys.S: // Scale modifier.
                    if (e.Modifiers == Keys.Shift) scale -= 0.1f;
                    else scale += 0.1f;
                    break;
                case Keys.PageUp: // Decrease Z.
                    translate.z -= 0.1f;
                    break;
                case Keys.PageDown: // Increase Z.
                    translate.z += 0.1f;
                    break;
                case Keys.Right: // Increase X.
                    translate.x += 0.1f;
                    break;
                case Keys.Left: // Decrease X.
                    translate.x -= 0.1f;
                    break;
                case Keys.Up: // Increase Y.
                    translate.y += 0.1f;
                    break;
                case Keys.Down: // Decrease Y.
                    translate.y -= 0.1f;
                    break;
                case Keys.X: // Rotate X.
                    if (e.Modifiers == Keys.Shift) rotate.x -= 1.0f;
                    else rotate.x += 1.0f;
                    break;
                case Keys.Y: // Rotate Y.
                    if (e.Modifiers == Keys.Shift) rotate.y -= 1.0f;
                    else rotate.y += 1.0f;
                    break;
                case Keys.Z: // Rotate Z.
                    if (e.Modifiers == Keys.Shift) rotate.z -= 1.0f;
                    else rotate.z += 1.0f;
                    break;
                case Keys.R: // R Modifier
                    if (e.Modifiers == Keys.Shift) r -= 0.1f;
                    else r += 0.1f;
                    break;
                case Keys.D: // Distance modifier
                    if (e.Modifiers == Keys.Shift) d -= 0.1f;
                    else d += 0.1f;
                    break;
                case Keys.P: // Phi modifier
                    if (e.Modifiers == Keys.Shift) phi -= 0.1f;
                    else phi += 0.1f;
                    break;
                case Keys.T: // Theta modifier
                    if (e.Modifiers == Keys.Shift) theta -= 0.1f;
                    else theta += 0.1f;
                    break;
                case Keys.A: // Start animation.
                    timer.Start();
                    break;
                case Keys.C: // Reset to defaults.
                    ResetToDefaults();
                    break;
                default:
                    break;
            }

            /* Refresh display */
            Invalidate();
        }

        void ResetToDefaults()
        {
            scale = 1.0f;
            translate.x = 0.0f;
            translate.y = 0.0f;
            translate.z = 0.0f;
            rotate.x = 0.0f;
            rotate.y = 0.0f;
            rotate.z = 0.0f;

            d = 800.0f;
            r = 10.0f;
            phi = -10.0f;
            theta = -100.0f;

            // Reset and stop animation.
            animation = animation_phase.Phase1_start;
            timer.Stop();

            /* Refresh display */
            Invalidate();
        }
    }
}
