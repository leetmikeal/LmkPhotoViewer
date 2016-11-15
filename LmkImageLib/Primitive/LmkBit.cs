using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace LmkImageLib
{
    /// <summary>
    /// 1-bit image
    /// </summary>
    [DataContract(Name = "")]
    public class LmkBit : ICloneable
    {
        private LmkImageClrLib.LmkBit body = new LmkImageClrLib.LmkBit();

        /// <summary>
        /// Copy constructor
        /// </summary>
        /// <param name="self">copied object</param>
        public LmkBit(LmkBit self)
            :this(self.body)
        {
        }

        /// <summary>
        /// Copy constructor
        /// </summary>
        /// <param name="bodySource"></param>
        internal LmkBit(LmkImageClrLib.LmkBit bodySource)
        {
            this.body = body.Clone();
        }

        #region ICloneable

        public LmkBit Clone()
        {
            return new LmkBit(this);
        }

        object ICloneable.Clone()
        {
            return this.Clone();
        }

        #endregion ICloneable
    }
}
