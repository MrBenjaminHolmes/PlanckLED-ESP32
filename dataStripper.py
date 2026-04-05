import pandas as pd
import numpy as np

# Initialize final DataFrame with PWM column
finalDf = pd.DataFrame({"PWM": range(256)})

for colour in ["Red", "Yellow", "Green", "Blue"]:
    # Load and clean dataset
    data = pd.read_csv(f"TestData{colour}.csv")
    data = data.drop(["Timestamp", "Type"], axis=1)
    data["Value"] = data["Value"].str.replace(r'\\r\\n', '', regex=True)
    data[["PWM", "Reading"]] = data["Value"].str.split(",", expand=True).astype(int)
    
    mean_readings = []
    for pwm in range(256):
        pwm_values = data[data["PWM"] == pwm]["Reading"]
        if len(pwm_values) == 0:
            mean_readings.append(0) 
            continue
        
        # IQR outlier removal
        Q1 = np.percentile(pwm_values, 25)
        Q3 = np.percentile(pwm_values, 75)
        IQR = Q3 - Q1
        mask = (pwm_values >= Q1 - 1.5*IQR) & (pwm_values <= Q3 + 1.5*IQR)
        cleaned_values = pwm_values[mask]
        
        # Take mean of cleaned values
        mean_readings.append(cleaned_values.mean())
    
    # 
    finalDf[colour] = mean_readings

# Save 
finalDf.to_csv("ProcessedData_AllColours.csv", index=False)
print(finalDf.head())