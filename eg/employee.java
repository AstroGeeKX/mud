// Employee.java
@Entity
public class Employee {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String name;
    private String department;
    private String position;
    // Getters and Setters
}

// EmployeeRepository.java
public interface EmployeeRepository extends JpaRepository<Employee, Long> {
}

// EmployeeService.java
@Service
public class EmployeeService {
    @Autowired
    private EmployeeRepository employeeRepository;

    public List<Employee> getAllEmployees() {
        return employeeRepository.findAll();
    }

    public Employee addEmployee(Employee employee) {
        return employeeRepository.save(employee);
    }

    public Employee editEmployee(Employee employee) {
        return employeeRepository.save(employee);
    }

    public void deleteEmployee(Long id) {
        employeeRepository.deleteById(id);
    }
}

// EmployeeController.java
@Controller
@RequestMapping("/employee")
public class EmployeeController {
    @Autowired
    private EmployeeService employeeService;

    @GetMapping("/view")
    public String viewEmployees(Model model) {
        List<Employee> employees = employeeService.getAllEmployees();
        model.addAttribute("employees", employees);
        return "employeeView";
    }

    @PostMapping("/add")
    public String addEmployee(Employee employee) {
        employeeService.addEmployee(employee);
        return "redirect:/employee/view";
    }
    
    @PostMapping("/edit")
    public String editEmployee(Employee employee) {
        employeeService.editEmployee(employee);
        return "redirect:/employee/view";
    }

    @PostMapping("/delete/{id}")
    public String deleteEmployee(@PathVariable Long id) {
        employeeService.deleteEmployee(id);
        return "redirect:/employee/view";
    }
}