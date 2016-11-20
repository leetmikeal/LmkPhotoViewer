using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace LmkPhotoViewer
{
    public class CommandArgumentException : InvalidOperationException
    {
        // 概要:
        //     Initializes a new instance of the System.CommandArgumentException class.
        public CommandArgumentException()
            :base()
        {

        }
        //
        // 概要:
        //     Initializes a new instance of the System.CommandArgumentException class
        //     with a specified error message.
        //
        // パラメーター:
        //   message:
        //     The message that describes the error.
        public CommandArgumentException(string message)
            :base(message)
        {

        }
        //
        // 概要:
        //     Initializes a new instance of the System.CommandArgumentException class
        //     with serialized data.
        //
        // パラメーター:
        //   info:
        //     The object that holds the serialized object data.
        //
        //   context:
        //     The contextual information about the source or destination.
        protected CommandArgumentException(SerializationInfo info, StreamingContext context)
            :base(info, context)
        {

        }
        //
        // 概要:
        //     Initializes a new instance of the System.CommandArgumentException class
        //     with a specified error message and a reference to the inner exception that
        //     is the cause of this exception.
        //
        // パラメーター:
        //   message:
        //     The error message that explains the reason for the exception.
        //
        //   innerException:
        //     The exception that is the cause of the current exception. If the innerException
        //     parameter is not a null reference (Nothing in Visual Basic), the current
        //     exception is raised in a catch block that handles the inner exception.
        public CommandArgumentException(string message, Exception innerException)
            :base(message, innerException)
        {

        }
    }
}
