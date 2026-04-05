import pandas as pd

data = pd.read_csv("testRandomData.csv")

data = data.drop(["Timestamp", "Type"], axis=1)

data["Value"] = data["Value"].str.replace(r'\\r\\n', '', regex=True)
data[["PWM","Reading"]] = data["Value"].str.split(",", expand=True).astype(int)
data = data.drop(["Value"], axis=1)
print(data)
data.to_csv("ProcessedData.csv",index=False)