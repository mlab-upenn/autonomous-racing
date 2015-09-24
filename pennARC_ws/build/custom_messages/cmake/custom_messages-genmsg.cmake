# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "custom_messages: 1 messages, 0 services")

set(MSG_I_FLAGS "-Icustom_messages:/home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/src/custom_messages/msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(custom_messages_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(custom_messages
  "/home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/src/custom_messages/msg/driveMessage.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/custom_messages
)

### Generating Services

### Generating Module File
_generate_module_cpp(custom_messages
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/custom_messages
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(custom_messages_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(custom_messages_generate_messages custom_messages_generate_messages_cpp)

# target for backward compatibility
add_custom_target(custom_messages_gencpp)
add_dependencies(custom_messages_gencpp custom_messages_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS custom_messages_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(custom_messages
  "/home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/src/custom_messages/msg/driveMessage.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/custom_messages
)

### Generating Services

### Generating Module File
_generate_module_lisp(custom_messages
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/custom_messages
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(custom_messages_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(custom_messages_generate_messages custom_messages_generate_messages_lisp)

# target for backward compatibility
add_custom_target(custom_messages_genlisp)
add_dependencies(custom_messages_genlisp custom_messages_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS custom_messages_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(custom_messages
  "/home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/src/custom_messages/msg/driveMessage.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/custom_messages
)

### Generating Services

### Generating Module File
_generate_module_py(custom_messages
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/custom_messages
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(custom_messages_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(custom_messages_generate_messages custom_messages_generate_messages_py)

# target for backward compatibility
add_custom_target(custom_messages_genpy)
add_dependencies(custom_messages_genpy custom_messages_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS custom_messages_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/custom_messages)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/custom_messages
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(custom_messages_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/custom_messages)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/custom_messages
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(custom_messages_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/custom_messages)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/custom_messages\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/custom_messages
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(custom_messages_generate_messages_py std_msgs_generate_messages_py)
