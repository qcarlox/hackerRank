#https://www.hackerrank.com/challenges/the-company
select  company.company_code, 
        company.founder, 
        lead_temp.lead_manager_count,
        senior_temp.senior_manager_count,
        manager_temp.manager_count,
        employee_temp.employee_count
from company,
(
    select company_code, count(distinct lead_manager_code) as lead_manager_count
    from lead_manager 
    group by company_code
) as lead_temp,

(
    select company_code, count(distinct senior_manager_code) as senior_manager_count
    from senior_manager
    group by company_code
) as senior_temp,

(
    select company_code, count(distinct manager_code) as manager_count
    from manager
    group by company_code
) as manager_temp,

(
    select company_code, count(distinct employee_code) as employee_count
    from employee
    group by company_code
) as employee_temp
where company.company_code = lead_temp.company_code 
and company.company_code = senior_temp.company_code
and company.company_code = manager_temp.company_code
and company.company_code = employee_temp.company_code
order by company.company_code
