namespace LmkPhotoViewer.Model
{
    using System;
    using System.Linq;
    using LmkImageLib;
    using LmkImageLib.Wpf;
    using System.Windows.Input;
    using LmkPhotoViewer.View.Controls;
    using System.Windows.Media;
    using System.ComponentModel;
    using System.Linq.Expressions;


    public class ModelBase : INotifyPropertyChanged
    {
        #region INotifyPropertyChanged member

        public event PropertyChangedEventHandler PropertyChanged;

        protected void RaisePropertyChanged(string name)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(name));
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1006:DoNotNestGenericTypesInMemberSignatures"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1011:ConsiderPassingBaseTypesAsParameters")]
        protected void RaisePropertyChanged<T>(Expression<Func<T>> propertyExpression)
        {
            // Livet‚ÌŽÀ‘•
            if (propertyExpression == null) 
                throw new ArgumentNullException("propertyExpression");
            if (!(propertyExpression.Body is MemberExpression)) 
                throw new NotSupportedException("");
            var memberExpression = (MemberExpression)propertyExpression.Body;
            RaisePropertyChanged(memberExpression.Member.Name);
        }
        
        #endregion

    }
}