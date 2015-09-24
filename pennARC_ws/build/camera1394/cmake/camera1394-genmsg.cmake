# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "camera1394: 0 messages, 2 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(camera1394_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/SetCameraRegisters.srv" NAME_WE)
add_custom_target(_camera1394_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera1394" "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/SetCameraRegisters.srv" ""
)

get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/GetCameraRegisters.srv" NAME_WE)
add_custom_target(_camera1394_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera1394" "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/GetCameraRegisters.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(camera1394
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/SetCameraRegisters.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera1394
)
_generate_srv_cpp(camera1394
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/GetCameraRegisters.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera1394
)

### Generating Module File
_generate_module_cpp(camera1394
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera1394
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(camera1394_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(camera1394_generate_messages camera1394_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/SetCameraRegisters.srv" NAME_WE)
add_dependencies(camera1394_generate_messages_cpp _camera1394_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/GetCameraRegisters.srv" NAME_WE)
add_dependencies(camera1394_generate_messages_cpp _camera1394_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(camera1394_gencpp)
add_dependencies(camera1394_gencpp camera1394_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS camera1394_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(camera1394
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/SetCameraRegisters.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera1394
)
_generate_srv_lisp(camera1394
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/GetCameraRegisters.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera1394
)

### Generating Module File
_generate_module_lisp(camera1394
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera1394
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(camera1394_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(camera1394_generate_messages camera1394_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/SetCameraRegisters.srv" NAME_WE)
add_dependencies(camera1394_generate_messages_lisp _camera1394_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/GetCameraRegisters.srv" NAME_WE)
add_dependencies(camera1394_generate_messages_lisp _camera1394_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(camera1394_genlisp)
add_dependencies(camera1394_genlisp camera1394_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS camera1394_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(camera1394
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/SetCameraRegisters.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera1394
)
_generate_srv_py(camera1394
  "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/GetCameraRegisters.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera1394
)

### Generating Module File
_generate_module_py(camera1394
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera1394
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(camera1394_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(camera1394_generate_messages camera1394_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/SetCameraRegisters.srv" NAME_WE)
add_dependencies(camera1394_generate_messages_py _camera1394_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/myGit/autonomous-racing/pennARC_ws/src/camera1394/srv/GetCameraRegisters.srv" NAME_WE)
add_dependencies(camera1394_generate_messages_py _camera1394_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(camera1394_genpy)
add_dependencies(camera1394_genpy camera1394_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS camera1394_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera1394)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera1394
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(camera1394_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera1394)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera1394
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(camera1394_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera1394)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera1394\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera1394
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(camera1394_generate_messages_py std_msgs_generate_messages_py)
