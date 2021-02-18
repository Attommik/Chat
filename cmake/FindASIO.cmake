include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(ASIO REQUIRED_VARS ASIO_INCLUDE_DIR)

if (${ASIO_FOUND})
    add_library(ASIO INTERFACE IMPORTED)
    set_target_properties(ASIO PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES ${ASIO_INCLUDE_DIR})
endif ()
