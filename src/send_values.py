import serial
import time

def send_values(serial_port, baud_rate, alt_steps, az_steps):
    with serial.Serial(serial_port, baud_rate, timeout=1) as ser:
        time.sleep(2)  # Wait for the serial connection to initialize
        ser.write(f"{alt_steps},{az_steps}\n".encode())

def main():
    serial_port = '/dev/ttyUSB0'  # Change this to your Arduino's serial port
    baud_rate = 9600
    alt_steps = 3
    az_steps = 6

    while True:
        send_values(serial_port, baud_rate, alt_steps, az_steps)
        time.sleep(10)  # Send values every 10 seconds

if __name__ == "__main__":
    main()