# -*- coding: utf-8 -*-
import numpy as np

def find_anomalies_z_score(list_data):
  outliers = []
  
  std_data = np.std(list_data); print('std:', std_data)
  mean_data = np.mean(list_data); print('mean:', mean_data)
  anomaly_cut_off = std_data * 3; print('anomaly_cut_off:', anomaly_cut_off)

  lower_limit  = mean_data - anomaly_cut_off; print('lower_limit', lower_limit)
  upper_limit = mean_data + anomaly_cut_off; print('upper_limit', upper_limit)

  for outlier in list_data:
          if outlier > upper_limit or outlier < lower_limit:
              outliers.append(outlier)
              
  if len(outliers) == 0:
    print('outlier is not found')

  return outliers

if __name__ == '__main__':
    data = 5 * np.random.randn(1000) + 50
    result = find_anomalies_z_score(data)
    print('outliers : ', result)
