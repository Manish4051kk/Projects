MINIMUM_CODONS = 5  # Minimum number of codons a valid protein must have
MINIMUM_CG_MASS_PERCENTAGE = 30  # Minimum percentage of mass from C and G for a protein to be valid
NUM_UNIQUE_NUCLEOTIDES = 4  # Number of unique nucleotides (A, C, G, T)
NUCLEOTIDES_PER_CODON = 3  # Number of nucleotides per codon

def user_input_output():
    user_input_info = []

    input_file_name = input("Input file name? ")
    output_file_name = input("Output file name? ")

    with open(input_file_name) as in_file:
        in_text = in_file.readlines()

    user_input_info.append(in_text)
    user_input_info.append(output_file_name)

    return user_input_info

def is_protein(final_sequence, C_mass, G_mass, total_mass):
    t_or_f = "NO"
    percent_calc = ((C_mass + G_mass) / total_mass) * 100

    if final_sequence.startswith('ATG'):
        if final_sequence.endswith(('TAA', 'TAG', 'TGA')):
            if (len(final_sequence) / NUCLEOTIDES_PER_CODON) >= MINIMUM_CODONS:
                if percent_calc >= MINIMUM_CG_MASS_PERCENTAGE:
                    t_or_f = "YES"
    return t_or_f

def output():
    info = user_input_output()
    text = info[0]
    output_file_name = info[1]

    with open(output_file_name, 'w') as output:
        for i in range(0, len(text), 2):
            Region_name = text[i].strip()
            nucleotides = text[i + 1].strip()
            sequence = nucleotides.upper()
            counts = {'A': 0, 'C': 0, 'G': 0, 'T': 0, '-': 0}

            for nuc in sequence:
                if nuc in counts:
                    counts[nuc] += 1
            counts_list = [counts['A'], counts['C'], counts['G'], counts['T'], counts['-']]

            final_sequence = "".join([nuc for nuc in sequence if nuc != '-'])

            sequences_in_groups_of_3 = [final_sequence[i:i + NUCLEOTIDES_PER_CODON] for i in range(0, len(final_sequence), NUCLEOTIDES_PER_CODON)]

            A_mass = counts_list[0] * 135.128
            C_mass = counts_list[1] * 111.103
            G_mass = counts_list[2] * 151.128
            T_mass = counts_list[3] * 125.107
            Junk = counts_list[4] * 100.0
            total_mass = A_mass + C_mass + G_mass + T_mass + Junk

            A_per = round((A_mass / total_mass) * 100, 1)
            C_per = round((C_mass / total_mass) * 100, 1)
            G_per = round((G_mass / total_mass) * 100, 1)
            T_per = round((T_mass / total_mass) * 100, 1)

            percents = [A_per, C_per, G_per, T_per]

            output.write(f"Region Name: {Region_name}\n")
            output.write(f"Nucleotides: {nucleotides}\n")
            output.write(f"Nuc. Counts: {counts_list[0:NUM_UNIQUE_NUCLEOTIDES]}\n")
            output.write(f"Total Mass%: {percents} of {round(total_mass, 1)}\n")
            output.write(f"Condons List: {sequences_in_groups_of_3}\n")
            output.write(f"Is Protein: {is_protein(final_sequence, C_mass, G_mass, total_mass)}\n\n")

def main():
    print("This program reports information about DNA")
    print("nucleotide sequences that may encode proteins.")
    output()

main()
