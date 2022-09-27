# Inverting keys and values in a dictionary

dictionary_1 = {'k1': 'v1', 'k2': 'v2', 'k3': 'v3', 'k4': 'v4', 'k5': 'v5'}

values_dict2 = list(dictionary_1.keys())
keys_dict2 = list(dictionary_1.values())

dictionary_2 = dict(zip(keys_dict2, values_dict2))

print('Original Dictionary = ', dictionary_1)
print('Inverted Dictionary = ', dictionary_2)
