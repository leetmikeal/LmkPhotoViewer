using LmkPhotoViewer.View.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace LmkPhotoViewer.Model.Controls
{
    public interface IMovableImageMatrix
    {

        /// <summary>
        /// Image zoom rate step
        /// </summary>
        double ZoomStep { get; set; }
        /// <summary>
        /// Image display matrix
        /// </summary>
        Matrix Matrix { get; set; }
    }

    public static class MovableImageMatrixExtension
    {
        /// <summary>
        /// Scale image at given center position.
        /// For control from model, this method implemented as extension method.
        /// </summary>
        /// <param name="self">interface has matrix property</param>
        /// <param name="centerX">column of center</param>
        /// <param name="centerY">row of center</param>
        /// <param name="zoomType">zoom up/down</param>
        public static void Scale(this IMovableImageMatrix self, double centerX, double centerY, MovableImageZoomType zoomType)
        {
            Matrix matrix = self.Matrix;
            double rate = 1.0;
            if (zoomType == MovableImageZoomType.ZoomUp)
                rate = 1 + self.ZoomStep;
            else if (zoomType == MovableImageZoomType.ZoomDown)
                rate = 1 - self.ZoomStep;

            matrix.ScaleAt(rate, rate, centerX, centerY);
            self.Matrix = matrix;
        }
    }
}
