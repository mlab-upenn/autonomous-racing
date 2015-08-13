# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "beginner_tutorials: 3 messages, 0 services")

set(MSG_I_FLAGS "-Ibeginner_tutorials:/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Ibeginner_tutorials:/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg;-Icustom_messages:/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/custom_messages/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(beginner_tutorials_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/Num.msg" NAME_WE)
add_custom_target(_beginner_tutorials_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "beginner_tutorials" "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/Num.msg" ""
)

get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveMessage.msg" NAME_WE)
add_custom_target(_beginner_tutorials_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "beginner_tutorials" "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveMessage.msg" ""
)

get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveCmd.msg" NAME_WE)
add_custom_target(_beginner_tutorials_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "beginner_tutorials" "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveCmd.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(beginner_tutorials
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beginner_tutorials
)
_generate_msg_cpp(beginner_tutorials
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveMessage.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beginner_tutorials
)
_generate_msg_cpp(beginner_tutorials
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beginner_tutorials
)

### Generating Services

### Generating Module File
_generate_module_cpp(beginner_tutorials
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beginner_tutorials
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(beginner_tutorials_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(beginner_tutorials_generate_messages beginner_tutorials_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/Num.msg" NAME_WE)
add_dependencies(beginner_tutorials_generate_messages_cpp _beginner_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveMessage.msg" NAME_WE)
add_dependencies(beginner_tutorials_generate_messages_cpp _beginner_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveCmd.msg" NAME_WE)
add_dependencies(beginner_tutorials_generate_messages_cpp _beginner_tutorials_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(beginner_tutorials_gencpp)
add_dependencies(beginner_tutorials_gencpp beginner_tutorials_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS beginner_tutorials_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(beginner_tutorials
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beginner_tutorials
)
_generate_msg_lisp(beginner_tutorials
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveMessage.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beginner_tutorials
)
_generate_msg_lisp(beginner_tutorials
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beginner_tutorials
)

### Generating Services

### Generating Module File
_generate_module_lisp(beginner_tutorials
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beginner_tutorials
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(beginner_tutorials_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(beginner_tutorials_generate_messages beginner_tutorials_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/Num.msg" NAME_WE)
add_dependencies(beginner_tutorials_generate_messages_lisp _beginner_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveMessage.msg" NAME_WE)
add_dependencies(beginner_tutorials_generate_messages_lisp _beginner_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveCmd.msg" NAME_WE)
add_dependencies(beginner_tutorials_generate_messages_lisp _beginner_tutorials_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(beginner_tutorials_genlisp)
add_dependencies(beginner_tutorials_genlisp beginner_tutorials_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS beginner_tutorials_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(beginner_tutorials
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beginner_tutorials
)
_generate_msg_py(beginner_tutorials
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveMessage.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beginner_tutorials
)
_generate_msg_py(beginner_tutorials
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beginner_tutorials
)

### Generating Services

### Generating Module File
_generate_module_py(beginner_tutorials
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beginner_tutorials
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(beginner_tutorials_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(beginner_tutorials_generate_messages beginner_tutorials_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/Num.msg" NAME_WE)
add_dependencies(beginner_tutorials_generate_messages_py _beginner_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveMessage.msg" NAME_WE)
add_dependencies(beginner_tutorials_generate_messages_py _beginner_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/beginner_tutorials/msg/driveCmd.msg" NAME_WE)
add_dependencies(beginner_tutorials_generate_messages_py _beginner_tutorials_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(beginner_tutorials_genpy)
add_dependencies(beginner_tutorials_genpy beginner_tutorials_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS beginner_tutorials_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beginner_tutorials)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beginner_tutorials
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(beginner_tutorials_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(beginner_tutorials_generate_messages_cpp beginner_tutorials_generate_messages_cpp)
add_dependencies(beginner_tutorials_generate_messages_cpp custom_messages_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beginner_tutorials)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beginner_tutorials
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(beginner_tutorials_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(beginner_tutorials_generate_messages_lisp beginner_tutorials_generate_messages_lisp)
add_dependencies(beginner_tutorials_generate_messages_lisp custom_messages_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beginner_tutorials)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beginner_tutorials\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beginner_tutorials
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(beginner_tutorials_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(beginner_tutorials_generate_messages_py beginner_tutorials_generate_messages_py)
add_dependencies(beginner_tutorials_generate_messages_py custom_messages_generate_messages_py)
