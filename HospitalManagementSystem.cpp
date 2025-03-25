#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Patient
{
  string name;
  int age;
  string gender;
  int id;
};

struct Doctor
{
  string name;
  int age;
  string gender;
  int id;
};

struct Appointment
{
  int patientID;
  int doctorID;
  string date;
};

class HospitalManagementSystem
{
private:
  vector<Patient> patients;
  vector<Doctor> doctors;
  vector<Appointment> appointments;

public:
  void addPatient()
  {
    Patient p;
    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, p.name);
    cout << "Enter Patient Age: ";
    cin >> p.age;
    cout << "Enter Patient Gender: ";
    cin >> p.gender;
    cout << "Enter Patient ID: ";
    cin >> p.id;

    patients.push_back(p);
    cout << "Patient added successfully!\n";
  }

  void addDoctor()
  {
    Doctor d;
    cout << "Enter Doctor Name: ";
    cin.ignore();
    getline(cin, d.name);
    cout << "Enter Doctor Age: ";
    cin >> d.age;
    cout << "Enter Doctor Gender: ";
    cin >> d.gender;
    cout << "Enter Doctor ID: ";
    cin >> d.id;

    doctors.push_back(d);
    cout << "Doctor added successfully!\n";
  }

  void scheduleAppointment()
  {
    Appointment a;
    cout << "Enter Patient ID: ";
    cin >> a.patientID;
    cout << "Enter Doctor ID: ";
    cin >> a.doctorID;
    cout << "Enter Appointment Date (DD-MM-YYYY): ";
    cin >> a.date;

    appointments.push_back(a);
    cout << "Appointment scheduled successfully!\n";
  }

  void viewPatients()
  {
    if (patients.empty())
    {
      cout << "No patients found.\n";
      return;
    }

    cout << "\nList of Patients:\n";
    for (const auto &p : patients)
    {
      cout << "ID: " << p.id << ", Name: " << p.name
           << ", Age: " << p.age << ", Gender: " << p.gender << endl;
    }
  }

  void viewDoctors()
  {
    if (doctors.empty())
    {
      cout << "No doctors found.\n";
      return;
    }

    cout << "\nList of Doctors:\n";
    for (const auto &d : doctors)
    {
      cout << "ID: " << d.id << ", Name: " << d.name
           << ", Age: " << d.age << ", Gender: " << d.gender << endl;
    }
  }

  void viewAppointments()
  {
    if (appointments.empty())
    {
      cout << "No appointments found.\n";
      return;
    }

    cout << "\nList of Appointments:\n";
    for (const auto &a : appointments)
    {
      cout << "Patient ID: " << a.patientID << ", Doctor ID: " << a.doctorID
           << ", Date: " << a.date << endl;
    }
  }

  void searchPatient()
  {
    int id;
    cout << "Enter Patient ID to search: ";
    cin >> id;

    for (const auto &p : patients)
    {
      if (p.id == id)
      {
        cout << "Patient Found: " << p.name << ", Age: " << p.age << ", Gender: " << p.gender << endl;
        return;
      }
    }
    cout << "Patient not found.\n";
  }

  void searchDoctor()
  {
    int id;
    cout << "Enter Doctor ID to search: ";
    cin >> id;

    for (const auto &d : doctors)
    {
      if (d.id == id)
      {
        cout << "Doctor Found: " << d.name << ", Age: " << d.age << ", Gender: " << d.gender << endl;
        return;
      }
    }
    cout << "Doctor not found.\n";
  }

  void deletePatient()
  {
    int id;
    cout << "Enter Patient ID to delete: ";
    cin >> id;

    for (auto it = patients.begin(); it != patients.end(); ++it)
    {
      if (it->id == id)
      {
        patients.erase(it);
        cout << "Patient deleted successfully!\n";
        return;
      }
    }
    cout << "Patient not found.\n";
  }

  void deleteDoctor()
  {
    int id;
    cout << "Enter Doctor ID to delete: ";
    cin >> id;

    for (auto it = doctors.begin(); it != doctors.end(); ++it)
    {
      if (it->id == id)
      {
        doctors.erase(it);
        cout << "Doctor deleted successfully!\n";
        return;
      }
    }
    cout << "Doctor not found.\n";
  }

  void cancelAppointment()
  {
    int pID, dID;
    cout << "Enter Patient ID for the appointment: ";
    cin >> pID;
    cout << "Enter Doctor ID for the appointment: ";
    cin >> dID;

    for (auto it = appointments.begin(); it != appointments.end(); ++it)
    {
      if (it->patientID == pID && it->doctorID == dID)
      {
        appointments.erase(it);
        cout << "Appointment cancelled successfully!\n";
        return;
      }
    }
    cout << "Appointment not found.\n";
  }

  void editPatient()
  {
    int id;
    cout << "Enter Patient ID to edit: ";
    cin >> id;

    for (auto &p : patients)
    {
      if (p.id == id)
      {
        cout << "Enter New Name: ";
        cin.ignore();
        getline(cin, p.name);
        cout << "Enter New Age: ";
        cin >> p.age;
        cout << "Enter New Gender: ";
        cin >> p.gender;
        cout << "Patient details updated successfully!\n";
        return;
      }
    }
    cout << "Patient not found.\n";
  }

  void editDoctor()
  {
    int id;
    cout << "Enter Doctor ID to edit: ";
    cin >> id;

    for (auto &d : doctors)
    {
      if (d.id == id)
      {
        cout << "Enter New Name: ";
        cin.ignore();
        getline(cin, d.name);
        cout << "Enter New Age: ";
        cin >> d.age;
        cout << "Enter New Gender: ";
        cin >> d.gender;
        cout << "Doctor details updated successfully!\n";
        return;
      }
    }
    cout << "Doctor not found.\n";
  }
};

int main()
{
  HospitalManagementSystem hms;
  int choice;

  while (true)
  {
    cout << "\nHospital Management System\n";
    cout << "1. Add Patient\n";
    cout << "2. Add Doctor\n";
    cout << "3. Schedule Appointment\n";
    cout << "4. View Patients\n";
    cout << "5. View Doctors\n";
    cout << "6. View Appointments\n";
    cout << "7. Search Patient\n";
    cout << "8. Search Doctor\n";
    cout << "9. Edit Patient\n";
    cout << "10. Edit Doctor\n";
    cout << "11. Delete Patient\n";
    cout << "12. Delete Doctor\n";
    cout << "13. Cancel Appointment\n";
    cout << "14. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      hms.addPatient();
      break;
    case 2:
      hms.addDoctor();
      break;
    case 3:
      hms.scheduleAppointment();
      break;
    case 4:
      hms.viewPatients();
      break;
    case 5:
      hms.viewDoctors();
      break;
    case 6:
      hms.viewAppointments();
      break;
    case 7:
      hms.searchPatient();
      break;
    case 8:
      hms.searchDoctor();
      break;
    case 9:
      hms.editPatient();
      break;
    case 10:
      hms.editDoctor();
      break;
    case 11:
      hms.deletePatient();
      break;
    case 12:
      hms.deleteDoctor();
      break;
    case 13:
      hms.cancelAppointment();
      break;
    case 14:
      cout << "Exiting the system.\n";
      return 0;
    default:
      cout << "Invalid choice! Try again.\n";
    }
  }
}
