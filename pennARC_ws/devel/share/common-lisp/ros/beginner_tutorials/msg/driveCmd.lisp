; Auto-generated. Do not edit!


(cl:in-package beginner_tutorials-msg)


;//! \htmlinclude driveCmd.msg.html

(cl:defclass <driveCmd> (roslisp-msg-protocol:ros-message)
  ((steering
    :reader steering
    :initarg :steering
    :type cl:float
    :initform 0.0)
   (throttle
    :reader throttle
    :initarg :throttle
    :type cl:float
    :initform 0.0))
)

(cl:defclass driveCmd (<driveCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <driveCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'driveCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beginner_tutorials-msg:<driveCmd> is deprecated: use beginner_tutorials-msg:driveCmd instead.")))

(cl:ensure-generic-function 'steering-val :lambda-list '(m))
(cl:defmethod steering-val ((m <driveCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-msg:steering-val is deprecated.  Use beginner_tutorials-msg:steering instead.")
  (steering m))

(cl:ensure-generic-function 'throttle-val :lambda-list '(m))
(cl:defmethod throttle-val ((m <driveCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-msg:throttle-val is deprecated.  Use beginner_tutorials-msg:throttle instead.")
  (throttle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <driveCmd>) ostream)
  "Serializes a message object of type '<driveCmd>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'steering))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'throttle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <driveCmd>) istream)
  "Deserializes a message object of type '<driveCmd>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'steering) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'throttle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<driveCmd>)))
  "Returns string type for a message object of type '<driveCmd>"
  "beginner_tutorials/driveCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'driveCmd)))
  "Returns string type for a message object of type 'driveCmd"
  "beginner_tutorials/driveCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<driveCmd>)))
  "Returns md5sum for a message object of type '<driveCmd>"
  "07077f1ca3b57b112f69aabcdabf600e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'driveCmd)))
  "Returns md5sum for a message object of type 'driveCmd"
  "07077f1ca3b57b112f69aabcdabf600e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<driveCmd>)))
  "Returns full string definition for message of type '<driveCmd>"
  (cl:format cl:nil "float32 steering~%float32 throttle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'driveCmd)))
  "Returns full string definition for message of type 'driveCmd"
  (cl:format cl:nil "float32 steering~%float32 throttle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <driveCmd>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <driveCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'driveCmd
    (cl:cons ':steering (steering msg))
    (cl:cons ':throttle (throttle msg))
))
