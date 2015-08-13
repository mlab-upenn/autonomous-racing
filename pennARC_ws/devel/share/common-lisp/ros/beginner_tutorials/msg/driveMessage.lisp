; Auto-generated. Do not edit!


(cl:in-package beginner_tutorials-msg)


;//! \htmlinclude driveMessage.msg.html

(cl:defclass <driveMessage> (roslisp-msg-protocol:ros-message)
  ((steering
    :reader steering
    :initarg :steering
    :type cl:fixnum
    :initform 0)
   (throttle
    :reader throttle
    :initarg :throttle
    :type cl:fixnum
    :initform 0))
)

(cl:defclass driveMessage (<driveMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <driveMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'driveMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beginner_tutorials-msg:<driveMessage> is deprecated: use beginner_tutorials-msg:driveMessage instead.")))

(cl:ensure-generic-function 'steering-val :lambda-list '(m))
(cl:defmethod steering-val ((m <driveMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-msg:steering-val is deprecated.  Use beginner_tutorials-msg:steering instead.")
  (steering m))

(cl:ensure-generic-function 'throttle-val :lambda-list '(m))
(cl:defmethod throttle-val ((m <driveMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-msg:throttle-val is deprecated.  Use beginner_tutorials-msg:throttle instead.")
  (throttle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <driveMessage>) ostream)
  "Serializes a message object of type '<driveMessage>"
  (cl:let* ((signed (cl:slot-value msg 'steering)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'throttle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <driveMessage>) istream)
  "Deserializes a message object of type '<driveMessage>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'steering) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'throttle) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<driveMessage>)))
  "Returns string type for a message object of type '<driveMessage>"
  "beginner_tutorials/driveMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'driveMessage)))
  "Returns string type for a message object of type 'driveMessage"
  "beginner_tutorials/driveMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<driveMessage>)))
  "Returns md5sum for a message object of type '<driveMessage>"
  "c4dd5817de7802d91e66008f92eca79e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'driveMessage)))
  "Returns md5sum for a message object of type 'driveMessage"
  "c4dd5817de7802d91e66008f92eca79e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<driveMessage>)))
  "Returns full string definition for message of type '<driveMessage>"
  (cl:format cl:nil "int16 steering~%int16 throttle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'driveMessage)))
  "Returns full string definition for message of type 'driveMessage"
  (cl:format cl:nil "int16 steering~%int16 throttle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <driveMessage>))
  (cl:+ 0
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <driveMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'driveMessage
    (cl:cons ':steering (steering msg))
    (cl:cons ':throttle (throttle msg))
))
