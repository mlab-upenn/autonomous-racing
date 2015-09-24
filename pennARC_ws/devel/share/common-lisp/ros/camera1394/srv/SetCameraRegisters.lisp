; Auto-generated. Do not edit!


(cl:in-package camera1394-srv)


;//! \htmlinclude SetCameraRegisters-request.msg.html

(cl:defclass <SetCameraRegisters-request> (roslisp-msg-protocol:ros-message)
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
   (value
    :reader value
    :initarg :value
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (mode
    :reader mode
    :initarg :mode
    :type cl:integer
    :initform 0))
)

(cl:defclass SetCameraRegisters-request (<SetCameraRegisters-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetCameraRegisters-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetCameraRegisters-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera1394-srv:<SetCameraRegisters-request> is deprecated: use camera1394-srv:SetCameraRegisters-request instead.")))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <SetCameraRegisters-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera1394-srv:type-val is deprecated.  Use camera1394-srv:type instead.")
  (type m))

(cl:ensure-generic-function 'offset-val :lambda-list '(m))
(cl:defmethod offset-val ((m <SetCameraRegisters-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera1394-srv:offset-val is deprecated.  Use camera1394-srv:offset instead.")
  (offset m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <SetCameraRegisters-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera1394-srv:value-val is deprecated.  Use camera1394-srv:value instead.")
  (value m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <SetCameraRegisters-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera1394-srv:mode-val is deprecated.  Use camera1394-srv:mode instead.")
  (mode m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<SetCameraRegisters-request>)))
    "Constants for message type '<SetCameraRegisters-request>"
  '((:TYPE_CONTROL . 0)
    (:TYPE_ABSOLUTE . 1)
    (:TYPE_FORMAT7 . 2)
    (:TYPE_ADVANCED_CONTROL . 3)
    (:TYPE_PIO . 4)
    (:TYPE_SIO . 5)
    (:TYPE_STROBE . 6))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'SetCameraRegisters-request)))
    "Constants for message type 'SetCameraRegisters-request"
  '((:TYPE_CONTROL . 0)
    (:TYPE_ABSOLUTE . 1)
    (:TYPE_FORMAT7 . 2)
    (:TYPE_ADVANCED_CONTROL . 3)
    (:TYPE_PIO . 4)
    (:TYPE_SIO . 5)
    (:TYPE_STROBE . 6))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetCameraRegisters-request>) ostream)
  "Serializes a message object of type '<SetCameraRegisters-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'offset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'offset)) ostream)
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
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mode)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetCameraRegisters-request>) istream)
  "Deserializes a message object of type '<SetCameraRegisters-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'offset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'offset)) (cl:read-byte istream))
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mode)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetCameraRegisters-request>)))
  "Returns string type for a service object of type '<SetCameraRegisters-request>"
  "camera1394/SetCameraRegistersRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetCameraRegisters-request)))
  "Returns string type for a service object of type 'SetCameraRegisters-request"
  "camera1394/SetCameraRegistersRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetCameraRegisters-request>)))
  "Returns md5sum for a message object of type '<SetCameraRegisters-request>"
  "703211788a5d6f08f820dfb1792ab51c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetCameraRegisters-request)))
  "Returns md5sum for a message object of type 'SetCameraRegisters-request"
  "703211788a5d6f08f820dfb1792ab51c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetCameraRegisters-request>)))
  "Returns full string definition for message of type '<SetCameraRegisters-request>"
  (cl:format cl:nil "~%uint8 TYPE_CONTROL=0~%uint8 TYPE_ABSOLUTE=1~%uint8 TYPE_FORMAT7=2~%uint8 TYPE_ADVANCED_CONTROL=3~%uint8 TYPE_PIO=4~%uint8 TYPE_SIO=5~%uint8 TYPE_STROBE=6~%~%uint8 type~%~%uint64 offset~%~%uint32[] value~%~%uint32 mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetCameraRegisters-request)))
  "Returns full string definition for message of type 'SetCameraRegisters-request"
  (cl:format cl:nil "~%uint8 TYPE_CONTROL=0~%uint8 TYPE_ABSOLUTE=1~%uint8 TYPE_FORMAT7=2~%uint8 TYPE_ADVANCED_CONTROL=3~%uint8 TYPE_PIO=4~%uint8 TYPE_SIO=5~%uint8 TYPE_STROBE=6~%~%uint8 type~%~%uint64 offset~%~%uint32[] value~%~%uint32 mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetCameraRegisters-request>))
  (cl:+ 0
     1
     8
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'value) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetCameraRegisters-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetCameraRegisters-request
    (cl:cons ':type (type msg))
    (cl:cons ':offset (offset msg))
    (cl:cons ':value (value msg))
    (cl:cons ':mode (mode msg))
))
;//! \htmlinclude SetCameraRegisters-response.msg.html

(cl:defclass <SetCameraRegisters-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass SetCameraRegisters-response (<SetCameraRegisters-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetCameraRegisters-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetCameraRegisters-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera1394-srv:<SetCameraRegisters-response> is deprecated: use camera1394-srv:SetCameraRegisters-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetCameraRegisters-response>) ostream)
  "Serializes a message object of type '<SetCameraRegisters-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetCameraRegisters-response>) istream)
  "Deserializes a message object of type '<SetCameraRegisters-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetCameraRegisters-response>)))
  "Returns string type for a service object of type '<SetCameraRegisters-response>"
  "camera1394/SetCameraRegistersResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetCameraRegisters-response)))
  "Returns string type for a service object of type 'SetCameraRegisters-response"
  "camera1394/SetCameraRegistersResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetCameraRegisters-response>)))
  "Returns md5sum for a message object of type '<SetCameraRegisters-response>"
  "703211788a5d6f08f820dfb1792ab51c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetCameraRegisters-response)))
  "Returns md5sum for a message object of type 'SetCameraRegisters-response"
  "703211788a5d6f08f820dfb1792ab51c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetCameraRegisters-response>)))
  "Returns full string definition for message of type '<SetCameraRegisters-response>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetCameraRegisters-response)))
  "Returns full string definition for message of type 'SetCameraRegisters-response"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetCameraRegisters-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetCameraRegisters-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetCameraRegisters-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetCameraRegisters)))
  'SetCameraRegisters-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetCameraRegisters)))
  'SetCameraRegisters-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetCameraRegisters)))
  "Returns string type for a service object of type '<SetCameraRegisters>"
  "camera1394/SetCameraRegisters")