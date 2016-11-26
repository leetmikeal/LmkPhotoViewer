using System;
using System.Linq;
using GalaSoft.MvvmLight;
using LmkImageLib;
using LmkImageLib.Wpf;
using GalaSoft.MvvmLight.CommandWpf;
using System.Windows.Input;
using LmkPhotoViewer.View.Controls;
using System.Windows.Media;

namespace LmkPhotoViewer.Model.Controls
{
    public class MovableImageState : ModelBase, IMovableImageMatrix
    {
        /// <summary>
        /// Initializes a new instance of the MainViewModel class.
        /// </summary>
        public MovableImageState()
        {
        }

        #region Method

        #endregion

        #region Property

        private double zoomStep = 0.1;

        /// <summary>
        /// Image display zoom step
        /// </summary>
        public double ZoomStep
        {
            get
            {
                return zoomStep;
            }
            set
            {
                zoomStep = value;
                RaisePropertyChanged(() => ZoomStep);
            }
        }

        private Matrix matrix;

        /// <summary>
        /// Image display matrix
        /// </summary>
        public Matrix Matrix
        {
            get
            {
                return matrix;
            }
            set
            {
                matrix = value;
                RaisePropertyChanged(() => Matrix);
            }
        }


        #endregion

    }
}