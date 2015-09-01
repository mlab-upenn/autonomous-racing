
(cl:in-package :asdf)

(defsystem "basic_path_plan-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "driveCmd" :depends-on ("_package_driveCmd"))
    (:file "_package_driveCmd" :depends-on ("_package"))
  ))