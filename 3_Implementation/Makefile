# MakeFile For Lunix

# Name of the project
PROJECT_NAME = 	Matrix_Calculator

# All source code files
SRC = main.c 



# Output directory
BUILD = build

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).out

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).out

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) 

# Create new build folder if not present
$(BUILD):
	mkdir build
