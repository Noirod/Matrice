project ( Matrice )

file(

        GLOB_RECURSE

        source_files

        src/*

)

add_executable (
	matrice
	${source_files}
)
