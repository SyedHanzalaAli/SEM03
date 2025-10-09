def div(n1 ,n2):
    try:
        return n1/n2
    
    except ZeroDivisionError:
        print("Error: You cannot divide by zero.")
    
    except ValueError:
        print("Error: Invalid input. Please enter valid integers.")
    
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

print(div(2,0))