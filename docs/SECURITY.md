# Security Policy

## Security Best Practices

To ensure the security of your deployment, please follow these best practices:

- **Keep Your Dependencies Up to Date**: Regularly update all dependencies to their latest versions to avoid known vulnerabilities. 
  
- **Secure Your CI/CD Pipeline**: Configure your CI/CD environment securely, using environment variables for sensitive information and restricting access to only essential services. Ensure that builds are performed in isolated environments.

- **Use Static Analysis Tools**: Integrate static analysis tools into your development process to catch potential vulnerabilities and code smells early. These tools should be configured to run automatically as part of your CI pipeline.

- **Enforce Code Reviews**: All changes to the codebase should be peer-reviewed to ensure adherence to security standards and coding best practices. Enable branch protection rules to require reviews before merging.

- **Implement Least Privilege**: Limit access to the repository, CI/CD pipelines, and production environments to only those individuals who absolutely need it. Apply the principle of least privilege to all aspects of your project.

## Reporting a Vulnerability

If you discover a security vulnerability in this project, we encourage you to report it as soon as possible. We take all vulnerabilities seriously and are committed to addressing them promptly.

### How to Report

- **Email**: Send an email to (mailto:hadlu202@student.otago.ac.nz) with the details of the vulnerability. Please include a clear description, reproduction steps, and any potential impact.

### What to Expect

- **Acknowledgment**: We will acknowledge receipt of your report within 48 hours.
- **Initial Assessment**: Within 5 days, we will conduct an initial assessment of the reported vulnerability.
- **Resolution**: If the vulnerability is confirmed, we will work on a fix, and you will be kept informed of our progress. The timeline for the resolution will depend on the severity and complexity of the issue.
- **Disclosure**: After a fix has been developed and tested, we will coordinate a disclosure timeline with you. We typically aim for responsible disclosure, providing a window for users to update their systems before publicizing the details.

### Security Patch Process

- **Security Patches**: We aim to release security patches promptly for all supported versions of the project. Users are encouraged to update to the latest version as soon as possible.

## Further Information

For more details on our security practices, you can also reach out to us at (mailto:hadlu202@student.otago.ac.nz) with any questions or concerns.