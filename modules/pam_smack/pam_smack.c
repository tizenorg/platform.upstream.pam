#define _GNU_SOURCE
#include <syslog.h>
#include <sys/smack.h>

#define PAM_SM_SESSION
#include <security/pam_modules.h>
#include <security/pam_modutil.h>


PAM_EXTERN int 
pam_sm_open_session (pam_handle_t *pamh,
		     int flags,
		     int argc,
		     const char **argv)
{
  if (smack_smackfs_path ()) {
    int rc = smack_set_label_for_self ("User");
    if (rc) {
      pam_syslog (pamh, LOG_WARNING, "couldn't set label");
    }
  }

  return PAM_SUCCESS;
}

PAM_EXTERN int
pam_sm_close_session (pam_handle_t *pamh, int flags,
                      int argc, const char **argv)
{
  return PAM_IGNORE;
}
