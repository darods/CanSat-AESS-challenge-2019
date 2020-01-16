// Log a data record.
void logData() {

  // Read normalized values gyro
  Vector norm = mpu.readNormalizeGyro();
  Vector normAccel = mpu.readNormalizeAccel();
  Activites act = mpu.readActivites();
  pitch = pitch + norm.YAxis * timeStep;
  roll = roll + norm.XAxis * timeStep;
  yaw = yaw + norm.ZAxis * timeStep;


  //Writing the data
  Serial.print(logTime);
  Serial.print(F(","));

  Serial.print(bmp.readAltitude(1013.25)-referencia);
  Serial.print(F(","));

  Serial.print(act.isFreeFall);
  Serial.print(F(","));
  
  Serial.print(bmp.readTemperature());
  Serial.print(F(","));


  Serial.print(bmp.readPressure());
  Serial.print(F(","));

  Serial.print(pitch);
  Serial.print(F(","));

  Serial.print(roll);
  Serial.print(F(","));

  Serial.print(yaw);
  Serial.print(F(","));

  Serial.print(normAccel.XAxis);
  Serial.print(F(","));

  Serial.print(normAccel.YAxis);
  Serial.print(F(","));

  Serial.print(normAccel.ZAxis);
  Serial.println();
}
