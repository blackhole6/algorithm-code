y_pred2 = lr_plus_p.predict(ploy_lr.fit_transform(X_test.reshape(-1, 1)))
print('MSE：',mean_absolute_error(y_test,y_pred2))
print('R2：',r2_score(y_test,y_pred2))