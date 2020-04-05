'''
:: Valid creditcard numbers for test ::

AMEX
    378282246310005
MASTERCARD
    5105105105105100
VISA
    4012888888881881
'''

from cs50 import get_int
# Number of cc
while True:
    card = get_int("What's your credit card number? ")
    # if the user enters with an character
    if card >= 0:
        break

firstDigits = 0
first_two_Digits = 0
digits = 0
numbers = 0

while card >= 1:
    rest = card % 10
    
    if card >= 10 and card < 100:
        first_two_Digits = card
    
    if card < 10:
        firstDigits = card
        
    if digits % 2 == 1:
        num = rest * 2
        
        if num > 9:
            num = num // 10 + num % 10
        
        numbers += num
    else:
        numbers += rest
        
    card //= 10
    
    digits += 1
    
# Validation cc
if numbers % 10 == 0:
    # Validation AMEX
    if digits == 15 and (first_two_Digits == 34 or first_two_Digits == 37):
        print("AMEX")
    # Validation MasterCard
    elif digits == 16 and first_two_Digits >= 51 and first_two_Digits <= 55:
        print("MASTERCARD")
    # Validation VISA
    elif (digits == 13 or digits == 16) and firstDigits == 4:
        print("VISA")
    else:
        # if the user enters an invalid number
        print("INVALID")
# if the user enters with an different numbers from the initial digits of the card
else:
    print("INVALID")