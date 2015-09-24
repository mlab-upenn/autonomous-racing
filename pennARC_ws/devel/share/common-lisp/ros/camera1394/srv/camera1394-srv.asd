
(cl:in-package :asdf)

(defsystem "camera1394-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "GetCameraRegisters" :depends-on ("_package_GetCameraRegisters"))
    (:file "_package_GetCameraRegisters" :depends-on ("_package"))
    (:file "SetCameraRegisters" :depends-on ("_package_SetCameraRegisters"))
    (:file "_package_SetCameraRegisters" :depends-on ("_package"))
  ))