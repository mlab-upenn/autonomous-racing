; Auto-generated. Do not edit!


(cl:in-package camera1394-srv)


;//! \htmlinclude GetCameraRegisters-request.msg.html

(cl:defclass <GetCameraRegisters-request> (roslisp-msg-protocol:ros-message)
  ((type
    :reader type
    :initarg :type
    :type cl:fixnum
    :initform 0)
   (offset
    :reader offset
    :initarg :offset
    :type cl:integer
    :initform 0)
   (num_regs
    :reader num_regs
    :initarg :num_regs
    :type cl:integer
    :initform 0)
   (mode
    :reader mode
    :initarg :mode
    :type cl:integer
    :initform 0))
)

(cl:defclass GetCameraRegisters-request (<GetCameraRegisters-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetCameraRegisters-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetCameraRegisters-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera1394-srv:<GetCameraRegisters-request> is deprecated: use camera1394-srv:GetCameraRegisters-request instead.")))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <GetCameraRegisters-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera1394-srv:type-val is deprecated.  Use camera1394-srv:type instead.")
  (type m))

(cl:ensure-generic-function 'offset-val :lambda-list '(m))
(cl:defmethod offset-val ((m <GetCameraRegisters-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera1394-srv:offset-val is deprecated.  Use camera1394-srv:offset instead.")
  (offset m))

(cl:ensure-generic-function 'num_regs-val :lambda-list '(m))
(cl:defmethod num_regs-val ((m <GetCameraRegisters-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera1394-srv:num_regs-val is deprecated.  Use camera1394-srv:num_regs instead.")
  (num_regs m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <GetCameraRegisters-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera1394-srv:mode-val is deprecated.  Use camera1394-srv:mode instead.")
  (mode m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<GetCameraRegisters-request>)))
    "Constants for message type '<GetCameraRegisters-request>"
  '((:TYPE_CONTROL . 0)
    (:TYPE_ABSOLUTE . 1)
    (:TYPE_FORMAT7 . 2)
    (:TYPE_ADVANCED_CONTROL . 3)
    (:TYPE_PIO . 4)
    (:TYPE_SIO . 5)
    (:TYPE_STROBE . 6))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'GetCameraRegisters-request)))
    "Constants for message type 'GetCameraRegisters-request"
  '((:TYPE_CONTROL . 0)
    (:TYPE_ABSOLUTE . 1)
    (:TYPE_FORMAT7 . 2)
    (:TYPE_ADVANCED_CONTROL . 3)
    (:TYPE_PIO . 4)
    (:TYPE_SIO . 5)
    (:TYPE_STROBE . 6))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetCameraRegisters-request>) ostream)
  "Serializes a message object of type '<GetCameraRegisters-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_regs)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'num_regs)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'num_regs)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'num_regs)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mode)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetCameraRegisters-request>) istream)
  "Deserializes a message object of type '<GetCameraRegisters-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_regs)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'num_regs)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'num_regs)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'num_regs)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mode)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetCameraRegisters-request>)))
  "Returns string type for a service object of type '<GetCameraRegisters-request>"
  "camera1394/GetCameraRegistersRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetCameraRegisters-request)))
  "Returns string type for a service object of type 'GetCameraRegisters-request"
  "camera1394/GetCameraRegistersRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetCameraRegisters-request>)))
  "Returns md5sum for a message object of type '<GetCameraRegisters-request>"
  "9597d397bc64c4c4fcaf24bbb15f0256")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetCameraRegisters-request)))
  "Returns md5sum for a message object of type 'GetCameraRegisters-request"
  "9597d397bc64c4c4fcaf24bbb15f0256")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetCameraRegisters-request>)))
  "Returns full string definition for message of type '<GetCameraRegisters-request>"
  (cl:format cl:nil "~%uint8 TYPE_CONTROL=0~%uint8 TYPE_ABSOLUTE=1~%uint8 TYPE_FORMAT7=2~%uint8 TYPE_ADVANCED_CONTROL=3~%uint8 TYPE_PIO=4~%uint8 TYPE_SIO=5~%uint8 TYPE_STROBE=6~%~%uint8 type~%~%uint64 offset~%~%uint32 num_regs~%~%uint32 mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetCameraRegisters-request)))
  "Returns full string definition for message of type 'GetCameraRegisters-request"
  (cl:format cl:nil "~%uint8 TYPE_CONTROL=0~%uint8 TYPE_ABSOLUTE=1~%uint8 TYPE_FORMAT7=2~%uint8 TYPE_ADVANCED_CONTROL=3~%uint8 TYPE_PIO=4~%uint8 TYPE_SIO=5~%uint8 TYPE_STROBE=6~%~%uint8 type~%~%uint64 offset~%~%uint32 num_regs~%~%uint32 mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetCameraRegisters-request>))
  (cl:+ 0
     1
     8
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetCameraRegisters-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetCameraRegisters-request
    (cl:cons ':type (type msg))
    (cl:cons ':offset (offset msg))
    (cl:cons ':num_regs (num_regs msg))
    (cl:cons ':mode (mode msg))
))
;//! \htmlinclude GetCameraRegisters-response.msg.html

(cl:defclass <GetCameraRegisters-response> (roslisp-msg-protocol:ros-message)
  ((value
    :reader value
    :initarg :value
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass GetCameraRegisters-response (<GetCameraRegisters-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetCameraRegisters-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetCameraRegisters-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera1394-srv:<GetCameraRegisters-response> is deprecated: use camera1394-srv:GetCameraRegisters-response instead.")))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <GetCameraRegisters-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera1394-srv:value-val is deprecated.  Use camera1394-srv:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetCameraRegisters-response>) ostream)
  "Serializes a message object of type '<GetCameraRegisters-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) ele) ostream))
   (cl:slot-value msg 'value))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetCameraRegisters-response>) istream)
  "Deserializes a message object of type '<GetCameraRegisters-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'value) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'value)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetCameraRegisters-response>)))
  "Returns string type for a service object of type '<GetCameraRegisters-response>"
  "camera1394/GetCameraRegistersResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetCameraRegisters-response)))
  "Returns string type for a service object of type 'GetCameraRegisters-response"
  "camera1394/GetCameraRegistersResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetCameraRegisters-response>)))
  "Returns md5sum for a message object of type '<GetCameraRegisters-response>"
  "9597d397bc64c4c4fcaf24bbb15f0256")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetCameraRegisters-response)))
  "Returns md5sum for a message object of type 'GetCameraRegisters-response"
  "9597d397bc64c4c4fcaf24bbb15f0256")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetCameraRegisters-response>)))
  "Returns full string definition for message of type '<GetCameraRegisters-response>"
  (cl:format cl:nil "~%uint32[] value~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetCameraRegisters-response)))
  "Returns full string definition for message of type 'GetCameraRegisters-response"
  (cl:format cl:nil "~%uint32[] value~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetCameraRegisters-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'value) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetCameraRegisters-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetCameraRegisters-response
    (cl:cons ':value (value msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetCameraRegisters)))
  'GetCameraRegisters-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetCameraRegisters)))
  'GetCameraRegisters-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetCameraRegisters)))
  "Returns string type for a service object of type '<GetCameraRegisters>"
  "camera1394/GetCameraRegisters")