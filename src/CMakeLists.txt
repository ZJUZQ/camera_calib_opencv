add_library (zhou_calib SHARED
		ccalib.cpp
		multicalib.cpp
		omnidir.cpp
		precomp.hpp
		randpattern.cpp)

target_link_libraries(zhou_calib ${THIRD_PARTY_LIBS})