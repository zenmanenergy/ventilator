# Sensors and Controls for Mechanical Ventilator
There are dozens possibly hundreds of designs for ventilators in response to the Covid-19 pandemic. Some of the designs are simpler than others. As of this posting there are no open source sensor and control systems to help ensure the patient receives the treatment they need. 

This respository is in response to that need. It contains the software to monitor a patient along with algorithms to change the behavior of a mechanical ventilator in response to the patient's needs. It is an attempt to reproduce the features available to respiratory therapists using highly available and low cost sensors. While it is not expected to replace professional ventilator our goal is to help 

# Everything in this repository is experimental!! BE WARNED
All code, pictures, videos, writings are provided by amateurs. NOTHING IN HERE HAS BEEN APPROVED BY THE FDA. You have been warned. If there are mistakes or errors in anything in this repository, no one that has participated in this project accepts any resposibility. If you make use of any work submitted here, you accept all resposibility.

# How a Ventilator Works
Starting with the absolute simplest explanation. A mechanical ventilator pushes oxygen (sometimes just 21% oxygen from air, sometimes higher by using a tank of pure oxygen) into the lungs and removes carbon dioxide. 

![Mechanical Ventilator](https://upload.wikimedia.org/wikipedia/commons/b/b5/Ventilators.jpg)

# What data needs to be measured?
This repsitory will contain code to measure and display information about a mechanical ventilator. 

- Air Stagnation Pressure
- Air Total Pressure
- Air mass flow rate
- Air speed
- Air temperature
- Air humidity
- Fractional Oxygen
- CO2 level
- Blood Oxygen level
- Heartbeats per minute

# What output controls does this need to provide?
- Increase/decrease air volume
- Increase/decrease air rate
- Positive End Expiratory Pressure rate

# How can you contribute to this project?
First contact Steve Nelson snelson@zenmanenergy.org let's brainstorm together so we can most effectively get the project off the ground. Then fork the project, make your changes and create pull requests so your improvements can be added into a master branch.
