import re

text_to_search = '''
abcdefghijklmnopqurtuvwxyz
ABCDEFGHIJKLMNOPQRSTUVWXYZ
1234567890

Ha HaHa

MetaCharacters (Need to be escaped):
. ^ $ * + ? { } [ ] \ | ( )

coreyms.com

321-555-4321
123.555.1234
123*555*1234
800-555-1234
900-555-1234

Mr. Schafer
Mr Smith
Ms Davis
Mrs. Robinson
Mr. T
'''

# pattern = re.compile(r"(\d{3}).\d{3}.(\d{4})")
# pattern = re.compile(r"Mr\.?")
pattern = re.compile(r"(\d{3})-(\d{3})-(\d{4})")

matches = pattern.finditer(text_to_search)

for match in matches:
    print(f"Match: {match.group(0)}")
    print(f"First 3 digits: {match.group(1)}")
    print(f"Next 3 digits: {match.group(2)}")
    print(f"Last 4 digits: {match.group(3)}\n")