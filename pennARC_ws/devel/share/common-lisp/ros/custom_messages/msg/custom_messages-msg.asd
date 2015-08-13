
(cl:in-package :asdf)

(defsystem "custom_messages-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "driveMessage" :depends-on ("_package_driveMessage"))
    (:file "_package_driveMessage" :depends-on ("_package"))
  ))