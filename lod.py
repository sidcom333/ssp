# Start the program
address = 0

# Check if input.dat exists; if not, create and add some text
try:
    with open("input.dat", "r") as fp1:
        pass  # Check if file exists
except FileNotFoundError:
    with open("input.dat", "w") as fp1:
        # Add some text to the file
        fp1.write("H\n0\n6\nT\n010203\nH\n9\n3\nT\n040506\nE\n")

# Open the files
with open("input.dat", "r") as fp1, open("output.dat", "w") as fp2:
    # Read the content
    input_data = fp1.readline().strip()

    # Using while loop perform the loop until character is not equal to E
    while input_data != "E":
        # Then compare the character is equal to H
        if input_data == "H":
            # If H, then fscanf in fp1 for input file for address, length, and input
            start = int(fp1.readline().strip())
            length = int(fp1.readline().strip())
            input_data = fp1.readline().strip()

        # Else if the character is T
        elif input_data == "T":
            # Perform fprintf in fp1 for input file for address, input[0], input[1], address+1, input[2], input[3], address+2, input[4], input[5]
            if len(input_data) >= 6:
                fp2.write(f"{address}\t{input_data[0]}{input_data[1]}\n")
                fp2.write(f"{address+1}\t{input_data[2]}{input_data[3]}\n")
                fp2.write(f"{address+2}\t{input_data[4]}{input_data[5]}\n")
                address += 3
            input_data = fp1.readline().strip()

        # Else if it is not H or T
        else:
            # Perform fprintf in fp2 for output file for address, input[0], input[1], address+1, input[2], input[3], address+2, input[4], input[5]
            if len(input_data) >= 6:
                fp2.write(f"{address}\t{input_data[0]}{input_data[1]}\n")
                fp2.write(f"{address+1}\t{input_data[2]}{input_data[3]}\n")
                fp2.write(f"{address+2}\t{input_data[4]}{input_data[5]}\n")
                address += 3
            input_data = fp1.readline().strip()

# Finally, terminate the program
print("Program terminated.")
